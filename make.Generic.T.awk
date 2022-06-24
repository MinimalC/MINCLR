#!/usr/bin/awk -f
# Gemeinfrei. Public Domain.
# 2019-2020 Hans Riehm

# Using Awk: Generic C - All about Generic_T0 and Generic_T0Type

function usage() {
    print "Use make.Generic.T.awk Namespace=MyProject Type=Product\\\n"\
          "    include/min/class.awk.h source/System/class.awk.inc">"/dev/stderr"
}

BEGIN { DEBUG=0 }

function __File_contains(fileName, string,  __,var) {
    if (system("test -s " fileName)) return
    while (getline var < fileName)
        if (var ~ string) return 1
    close(fileName)
    return
}

BEGINFILE {

    if (!Namespace) { error = "Namespace not defined."; nextfile }
    if (!Type) { error = Namespace".Type not defined."; nextfile }

    if (!__File_contains(FILENAME, "GENERIC")) {
        error = FILENAME" isn't GENERIC"; nextfile
    }

    if (FILENAME ~ /\.h$/) {
        ext = ".h"
        outputDir = "include/min"
    } else if (FILENAME ~ /\.c$/) {
        ext = ".c"
        outputDir = "source"
    } else if (FILENAME ~ /\.inc$/) {
        ext = ".inc"
        outputDir = "source"
    } else {
        error = "Unknown File Format: "FILENAME; nextfile
    }
    system("mkdir -p "outputDir)

    variables["Namespace"] = Namespace
    variables["Type"] = Type
    if (Type1) {
        variables["Namespace1"] = Namespace1
        variables["Type1"] = Type1
    }

    if (!auto) outputName = "."Namespace"."Type ext
    else outputName = Namespace"."Type".AUTO"ext
    output = outputDir"/"outputName
}

{ do {
    if (NR == 1) comment = $0
    if (!read) {
        if ($2 == "FileName") {
            gsub(/Generic\.T0/, Namespace"."Type, $3)
            gsub(/T0/, Namespace"."Type, $3)
            if (!auto) outputName = "."$3 ext
            else outputName = $3".AUTO"ext
            output = outputDir"/"outputName
        }
        else if ($2 == "Type1") {
            if ($3 == "required") if (!Type1){error="Type1 is required";nextfile}
        }
        else if ($2 == "seeAlso") {
            print $3
        }
        else if ($2 == "GENERIC") {
            read = 1; write = 1
            print comment > output # Print the First Line
            print "/* AUTOGEN */" >> output
        }
        continue
    }
    if ($1 == "##set") {
        if (!write) continue

        variableName = $2; operator = $3
        for (i = 1; i < 4; ++i) $(i) = ""; $0 = substr($0, 4); value = $0
        if (value ~ /^[ \t]*"/) value = substr(value, 2, length(value) - 2)
        else value = 0 + value

        variables[variableName] = value

        if (DEBUG) print "/* set "variableName" "operator" "value" */" >> output
        continue
    }
    if ($1 == "##unset") {
        if (!write) continue

        variableName = $2
        delete variables[variableName]

        if (DEBUG) print "/* unset "variableName" */" >> output
        continue
    }
    if ($1 == "##if") {
        variableName = $2; operator = $3
        for (i = 1; i < 4; ++i) $(i) = ""; $0 = substr($0, 4); value = $0
        if (value ~ /^[ \t]*"/) value = substr(value, 2, length(value) - 2)
        else value = 0 + value

             if (operator == "==")ifExpression = variables[variableName] == value
        else if (operator == "!=")ifExpression = variables[variableName] != value
        else if (operator == "~") ifExpression = variables[variableName] ~  value
        else if (operator == "!~")ifExpression = variables[variableName] !~ value
        else if (operator == ">=")ifExpression = variables[variableName] >= value
        else if (operator == ">") ifExpression = variables[variableName] >  value
        else if (operator == "<=")ifExpression = variables[variableName] <= value
        else if (operator == "<") ifExpression = variables[variableName] <  value

        if (ifExpression) write = 1
        else write = 0

        if (DEBUG)
    print "/* if "variableName" "operator" "value" => "ifExpression" */" >> output
        continue
    }
    if ($1 == "##else") {
        if ($2 == "if") {
            if (ifExpression || elseifExpression) { write = 0; continue }

            variableName = $3; operator = $4
            for (i = 1; i < 5; ++i) $(i) = ""; $0 = substr($0, 5); value = $0
            if (value ~ /^[ \t]*"/) value = substr(value, 2, length(value) - 2)
            else value = 0 + value

        if (operator == "==")     elseifExpression = variables[variableName] ==value
        else if (operator == "!=")elseifExpression = variables[variableName] !=value
        #else if (operator == "~")elseifExpression = variables[variableName]  ~value
        #else if(operator == "!~")elseifExpression = variables[variableName] !~value
        else if (operator == ">=")elseifExpression = variables[variableName] >=value
        else if (operator == ">") elseifExpression = variables[variableName]  >value
        else if (operator == "<=")elseifExpression = variables[variableName] <=value
        else if (operator == "<") elseifExpression = variables[variableName]  <value

        if (elseifExpression) write = 1
        else write = 0

        if (DEBUG)
print"/* else if "variableName" "operator" "value" => "elseifExpression" */">>output
        continue
        }
        if (ifExpression || elseifExpression) { write = 0; continue }

        write = 1

        if (DEBUG) print "/* else */" >> output
        continue
    }
    if ($1 == "##endif") {
        ifExpression = 0
        elseifExpression = 0
        write = 1

        if (DEBUG) print "/* endif */" >> output
        continue
    }
    #if ($1 == "##for") { }
    #if ($1 == "##next") { }
    #if ($1 == "##while") { }
    #if ($1 == "##do") { }
    #if ($1 == "##loop") { }

    if ($1 == "##info") {
        if (!write) continue

        $1 = ""; $0 = substr($0, 2); info = $0
        if (info ~ /^[ \t]*"/) info = substr(info, 2, length(info) - 2)

        print "/* INFO: "info" */" >> output
        continue
    }
    if ($1 == "##error") {
        if (!write) continue

        $1 = ""; $0 = substr($0, 2); error = $0
        if (error ~ /^[ \t]*"/) error = substr(error, 2, length(error) - 2)
        else if (!error) error = "!"

        print "/* ERROR "error" */" >> output
        continue
    }

    if (write) {
        for (variableName in variables) {
            varName = "#"variableName
            var = variables[variableName]
            gsub(varName, var)
        }
        while (i = index($0, "#(")) {
            expression = substr($0, i + 2)
            l = index(expression, ")")
            expression = substr(expression, 1, l)
            if (split(expression, expressionA, /[ \t]/)) {
                variableName = expressionA[1]
                operator = expressionA[2]
                value = expressionA[3]
                if (value ~ /^[ \t]*"/) value = substr(value, 2, length(value) - 2)
                else value = 0 + value

             if (operator == "+") expressionResult = variables[variableName] + value
        else if (operator == "-") expressionResult = variables[variableName] - value
        else if (operator == "*") expressionResult = variables[variableName] * value
        else if (operator == "/") expressionResult = variables[variableName] / value
        else if (operator == "%") expressionResult = variables[variableName] % value
        else if (operator == "^") expressionResult = variables[variableName] ^ value

            } else expressionResult = ""

            expressionL = substr($0, 1, i - 1)
            expressionR = substr($0, i + l + 2)
            $0 = expressionL expressionResult expressionR
        }

        if (Type1) {
            if (!Namespace1) Namespace1 = Namespace
            gsub(/Generic1\.T1/, Namespace1"."Type1)
            gsub(/Generic1_T1/, Namespace1"_"Type1)
            gsub(/_Generic1/, "_"Namespace1)
            gsub(/Generic1\./, Namespace1".")
            gsub(/"T1/, "\""Type1)
            gsub(/__T1/, "__"Type1)
            gsub(/_T1/, "_"Type1)
            gsub(/T1\./, Type1".")
        }
        gsub(/Generic\.T0/, Namespace"."Type)
        gsub(/Generic_T0/, Namespace"_"Type)
        gsub(/_Generic/, "_"Namespace)
        gsub(/Generic\./, Namespace".")
        gsub(/"T0/, "\""Type)
        gsub(/__T0/, "__"Type)
        gsub(/_T0/, "_"Type)
        gsub(/T0\./, Type".")

        # if ($0 !~ /^[ \t]*$/) print >> output
        # if ($0 != "") print >> output
        print >> output
    }

} while (0 < getline) }

ENDFILE {

    if (error) {
        if (info) { print "INFO: "info; info="" }
        if (DEBUG) { errorFile = outputDir"/."Namespace"."Type".ERROR"ext
            system("mv -f "output" "errorFile)
        } else system("rm -f "output)
        exit 1
    }

    if (read) {
        if (auto) {
            namespace_output = outputDir"/"Namespace".AUTO"ext
            if (!__File_contains(namespace_output, outputName)) {
                print "#include \""outputName"\"" >> namespace_output
                close(namespace_output)
            }
        }
        read=0
    }
} #
