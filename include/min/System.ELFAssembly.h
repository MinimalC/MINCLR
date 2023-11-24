/* Gemeinfrei. Public Domain. */
#if !defined(have_System_Type)
#include <min/System.Type.h>
#endif
#if !defined(have_System_ELFAssembly)

#define System_ELFAssembly_Magic  "\177ELF"

typedef System_UInt8 System_ELFAssembly_Class;
enum {
    System_ELFAssembly_Class_None,
    System_ELFAssembly_Class_32,
    System_ELFAssembly_Class_64,
};

typedef System_UInt8 System_ELFAssembly_Endianess;
enum {
    System_ELFAssembly_Endianess_None,
    System_ELFAssembly_Endianess_Little,
    System_ELFAssembly_Endianess_Big,
};

typedef System_UInt8 System_ELFAssembly_Version;
enum {
    System_ELFAssembly_Version_None,
    System_ELFAssembly_Version_Current,
};

typedef System_UInt8 System_ELFAssembly_ABI;
enum {
    System_ELFAssembly_ABI_SysV,
    System_ELFAssembly_ABI_HPUX,
    System_ELFAssembly_ABI_NetBSD,
    System_ELFAssembly_ABI_Linux,
    System_ELFAssembly_ABI_Solaris = 6,
    System_ELFAssembly_ABI_AIX,
    System_ELFAssembly_ABI_IRIX,
    System_ELFAssembly_ABI_FreeBSD,
    System_ELFAssembly_ABI_TRU64,
    System_ELFAssembly_ABI_Modesto,
    System_ELFAssembly_ABI_OpenBSD,
    System_ELFAssembly_ABI_ARM_EABI = 64,
    System_ELFAssembly_ABI_ARM = 97,
    System_ELFAssembly_ABI_Standalone = 255,
};

export struct System_Type  System_ELFAssembly_ABIType;

typedef System_UInt16 System_ELFAssembly_AssemblyType;
enum {
    System_ELFAssembly_AssemblyType_None,
    System_ELFAssembly_AssemblyType_Relocatable,
    System_ELFAssembly_AssemblyType_Executable,
    System_ELFAssembly_AssemblyType_Dynamic,
    System_ELFAssembly_AssemblyType_Core,
    System_ELFAssembly_AssemblyType_OSSpecificLow = 0xfe00,
    System_ELFAssembly_AssemblyType_OSSpecificHigh = 0xfeff,
    System_ELFAssembly_AssemblyType_ProcessorSpecificLow = 0xff00,
    System_ELFAssembly_AssemblyType_ProcessorSpecificHigh = 0xffff,
};

export struct System_Type  System_ELFAssembly_AssemblyTypeType;

typedef System_UInt16 System_ELFAssembly_Machine;
enum {
    System_ELFAssembly_Machine_None,
    System_ELFAssembly_Machine_M32 = 1,    /* AT&T WE 32100 */
    System_ELFAssembly_Machine_SPARC = 2,    /* SUN SPARC */
    System_ELFAssembly_Machine_386 = 3,    /* Intel 80386 */
    System_ELFAssembly_Machine_68K = 4,    /* Motorola m68k family */
    System_ELFAssembly_Machine_88K = 5,    /* Motorola m88k family */
    System_ELFAssembly_Machine_IAMCU = 6,    /* Intel MCU */
    System_ELFAssembly_Machine_860 = 7,    /* Intel 80860 */
    System_ELFAssembly_Machine_MIPS = 8,    /* MIPS R3000 big-endian */
    System_ELFAssembly_Machine_S370 = 9,    /* IBM System/370 */
    System_ELFAssembly_Machine_MIPS_RS3_LE = 10,    /* MIPS R3000 little-endian */
    /* reserved 11-14 */
    System_ELFAssembly_Machine_PARISC = 15,    /* HPPA */
    /* reserved 16 */
    System_ELFAssembly_Machine_VPP500 = 17,    /* Fujitsu VPP500 */
    System_ELFAssembly_Machine_SPARC32PLUS = 18,    /* Sun's "v8plus" */
    System_ELFAssembly_Machine_960 = 19,    /* Intel 80960 */
    System_ELFAssembly_Machine_PPC = 20,    /* PowerPC */
    System_ELFAssembly_Machine_PPC64 = 21,    /* PowerPC 64-bit */
    System_ELFAssembly_Machine_S390 = 22,    /* IBM S390 */
    System_ELFAssembly_Machine_SPU = 23,    /* IBM SPU/SPC */
    /* reserved 24-35 */
    System_ELFAssembly_Machine_V800 = 36,    /* NEC V800 series */
    System_ELFAssembly_Machine_FR20 = 37,    /* Fujitsu FR20 */
    System_ELFAssembly_Machine_RH32 = 38,    /* TRW RH-32 */
    System_ELFAssembly_Machine_RCE = 39,    /* Motorola RCE */
    System_ELFAssembly_Machine_ARM = 40,    /* ARM */
    System_ELFAssembly_Machine_FAKE_ALPHA = 41,    /* Digital Alpha */
    System_ELFAssembly_Machine_SH = 42,    /* Hitachi SH */
    System_ELFAssembly_Machine_SPARCV9 = 43,    /* SPARC v9 64-bit */
    System_ELFAssembly_Machine_TRICORE = 44,    /* Siemens Tricore */
    System_ELFAssembly_Machine_ARC = 45,    /* Argonaut RISC Core */
    System_ELFAssembly_Machine_H8_300 = 46,    /* Hitachi H8/300 */
    System_ELFAssembly_Machine_H8_300H = 47,    /* Hitachi H8/300H */
    System_ELFAssembly_Machine_H8S = 48,    /* Hitachi H8S */
    System_ELFAssembly_Machine_H8_500 = 49,    /* Hitachi H8/500 */
    System_ELFAssembly_Machine_IA_64 = 50,    /* Intel Merced */
    System_ELFAssembly_Machine_MIPS_X = 51,    /* Stanford MIPS-X */
    System_ELFAssembly_Machine_COLDFIRE = 52,    /* Motorola Coldfire */
    System_ELFAssembly_Machine_68HC12 = 53,    /* Motorola M68HC12 */
    System_ELFAssembly_Machine_MMA = 54,    /* Fujitsu MMA Multimedia Accelerator */
    System_ELFAssembly_Machine_PCP = 55,    /* Siemens PCP */
    System_ELFAssembly_Machine_NCPU = 56,    /* Sony nCPU embeeded RISC */
    System_ELFAssembly_Machine_NDR1 = 57,    /* Denso NDR1 microprocessor */
    System_ELFAssembly_Machine_STARCORE = 58,    /* Motorola Start*Core processor */
    System_ELFAssembly_Machine_ME16 = 59,    /* Toyota ME16 processor */
    System_ELFAssembly_Machine_ST100 = 60,    /* STMicroelectronic ST100 processor */
    System_ELFAssembly_Machine_TINYJ = 61,    /* Advanced Logic Corp. Tinyj emb.fam */
    System_ELFAssembly_Machine_AMD64 = 62,    /* AMD x86-64 architecture */
    System_ELFAssembly_Machine_PDSP = 63,    /* Sony DSP Processor */
    System_ELFAssembly_Machine_PDP10 = 64,    /* Digital PDP-10 */
    System_ELFAssembly_Machine_PDP11 = 65,    /* Digital PDP-11 */
    System_ELFAssembly_Machine_FX66 = 66,    /* Siemens FX66 microcontroller */
    System_ELFAssembly_Machine_ST9PLUS = 67,    /* STMicroelectronics ST9+ 8/16 mc */
    System_ELFAssembly_Machine_ST7 = 68,    /* STmicroelectronics ST7 8 bit mc */
    System_ELFAssembly_Machine_68HC16 = 69,    /* Motorola MC68HC16 microcontroller */
    System_ELFAssembly_Machine_68HC11 = 70,    /* Motorola MC68HC11 microcontroller */
    System_ELFAssembly_Machine_68HC08 = 71,    /* Motorola MC68HC08 microcontroller */
    System_ELFAssembly_Machine_68HC05 = 72,    /* Motorola MC68HC05 microcontroller */
    System_ELFAssembly_Machine_SVX = 73,    /* Silicon Graphics SVx */
    System_ELFAssembly_Machine_ST19 = 74,    /* STMicroelectronics ST19 8 bit mc */
    System_ELFAssembly_Machine_VAX = 75,    /* Digital VAX */
    System_ELFAssembly_Machine_CRIS = 76,    /* Axis Communications 32-bit emb.proc */
    System_ELFAssembly_Machine_JAVELIN = 77,    /* Infineon Technologies 32-bit emb.proc */
    System_ELFAssembly_Machine_FIREPATH = 78,    /* Element 14 64-bit DSP Processor */
    System_ELFAssembly_Machine_ZSP = 79,    /* LSI Logic 16-bit DSP Processor */
    System_ELFAssembly_Machine_MMIX = 80,    /* Donald Knuth's educational 64-bit proc */
    System_ELFAssembly_Machine_HUANY = 81,    /* Harvard University machine-independent object files */
    System_ELFAssembly_Machine_PRISM = 82,    /* SiTera Prism */
    System_ELFAssembly_Machine_AVR = 83,    /* Atmel AVR 8-bit microcontroller */
    System_ELFAssembly_Machine_FR30 = 84,    /* Fujitsu FR30 */
    System_ELFAssembly_Machine_D10V = 85,    /* Mitsubishi D10V */
    System_ELFAssembly_Machine_D30V = 86,    /* Mitsubishi D30V */
    System_ELFAssembly_Machine_V850 = 87,    /* NEC v850 */
    System_ELFAssembly_Machine_M32R = 88,    /* Mitsubishi M32R */
    System_ELFAssembly_Machine_MN10300 = 89,    /* Matsushita MN10300 */
    System_ELFAssembly_Machine_MN10200 = 90,    /* Matsushita MN10200 */
    System_ELFAssembly_Machine_PJ = 91,    /* picoJava */
    System_ELFAssembly_Machine_OPENRISC = 92,    /* OpenRISC 32-bit embedded processor */
    System_ELFAssembly_Machine_ARC_COMPACT = 93,    /* ARC International ARCompact */
    System_ELFAssembly_Machine_XTENSA = 94,    /* Tensilica Xtensa Architecture */
    System_ELFAssembly_Machine_VIDEOCORE = 95,    /* Alphamosaic VideoCore */
    System_ELFAssembly_Machine_TMM_GPP = 96,    /* Thompson Multimedia General Purpose Proc */
    System_ELFAssembly_Machine_NS32K = 97,    /* National Semi. 32000 */
    System_ELFAssembly_Machine_TPC = 98,    /* Tenor Network TPC */
    System_ELFAssembly_Machine_SNP1K = 99,    /* Trebia SNP 1000 */
    System_ELFAssembly_Machine_ST200 = 100,    /* STMicroelectronics ST200 */
    System_ELFAssembly_Machine_IP2K = 101,    /* Ubicom IP2xxx */
    System_ELFAssembly_Machine_MAX = 102,    /* MAX processor */
    System_ELFAssembly_Machine_CR = 103,    /* National Semi. CompactRISC */
    System_ELFAssembly_Machine_F2MC16 = 104,    /* Fujitsu F2MC16 */
    System_ELFAssembly_Machine_MSP430 = 105,    /* Texas Instruments msp430 */
    System_ELFAssembly_Machine_BLACKFIN = 106,    /* Analog Devices Blackfin DSP */
    System_ELFAssembly_Machine_SE_C33 = 107,    /* Seiko Epson S1C33 family */
    System_ELFAssembly_Machine_SEP = 108,    /* Sharp embedded microprocessor */
    System_ELFAssembly_Machine_ARCA = 109,    /* Arca RISC */
    System_ELFAssembly_Machine_UNICORE = 110,    /* PKU-Unity & MPRC Peking Uni. mc series */
    System_ELFAssembly_Machine_EXCESS = 111,    /* eXcess configurable cpu */
    System_ELFAssembly_Machine_DXP = 112,    /* Icera Semi. Deep Execution Processor */
    System_ELFAssembly_Machine_ALTERA_NIOS2 = 113,    /* Altera Nios II */
    System_ELFAssembly_Machine_CRX = 114,    /* National Semi. CompactRISC CRX */
    System_ELFAssembly_Machine_XGATE = 115,    /* Motorola XGATE */
    System_ELFAssembly_Machine_C166 = 116,    /* Infineon C16x/XC16x */
    System_ELFAssembly_Machine_M16C = 117,    /* Renesas M16C */
    System_ELFAssembly_Machine_DSPIC30F = 118,    /* Microchip Technology dsPIC30F */
    System_ELFAssembly_Machine_CE = 119,    /* Freescale Communication Engine RISC */
    System_ELFAssembly_Machine_M32C = 120,    /* Renesas M32C */
    /* reserved 121-130 */
    System_ELFAssembly_Machine_TSK3000 = 131,    /* Altium TSK3000 */
    System_ELFAssembly_Machine_RS08 = 132,    /* Freescale RS08 */
    System_ELFAssembly_Machine_SHARC = 133,    /* Analog Devices SHARC family */
    System_ELFAssembly_Machine_ECOG2 = 134,    /* Cyan Technology eCOG2 */
    System_ELFAssembly_Machine_SCORE7 = 135,    /* Sunplus S+core7 RISC */
    System_ELFAssembly_Machine_DSP24 = 136,    /* New Japan Radio (NJR) 24-bit DSP */
    System_ELFAssembly_Machine_VIDEOCORE3 = 137,    /* Broadcom VideoCore III */
    System_ELFAssembly_Machine_LATTICEMICO32 = 138,    /* RISC for Lattice FPGA */
    System_ELFAssembly_Machine_SE_C17 = 139,    /* Seiko Epson C17 */
    System_ELFAssembly_Machine_TI_C6000 = 140,    /* Texas Instruments TMS320C6000 DSP */
    System_ELFAssembly_Machine_TI_C2000 = 141,    /* Texas Instruments TMS320C2000 DSP */
    System_ELFAssembly_Machine_TI_C5500 = 142,    /* Texas Instruments TMS320C55x DSP */
    System_ELFAssembly_Machine_TI_ARP32 = 143,    /* Texas Instruments App. Specific RISC */
    System_ELFAssembly_Machine_TI_PRU = 144,    /* Texas Instruments Prog. Realtime Unit */
    /* reserved 145-159 */
    System_ELFAssembly_Machine_MMDSP_PLUS = 160,    /* STMicroelectronics 64bit VLIW DSP */
    System_ELFAssembly_Machine_CYPRESS_M8C = 161,    /* Cypress M8C */
    System_ELFAssembly_Machine_R32C = 162,    /* Renesas R32C */
    System_ELFAssembly_Machine_TRIMEDIA = 163,    /* NXP Semi. TriMedia */
    System_ELFAssembly_Machine_QDSP6 = 164,    /* QUALCOMM DSP6 */
    System_ELFAssembly_Machine_8051 = 165,    /* Intel 8051 and variants */
    System_ELFAssembly_Machine_STXP7X = 166,    /* STMicroelectronics STxP7x */
    System_ELFAssembly_Machine_NDS32 = 167,    /* Andes Tech. compact code emb. RISC */
    System_ELFAssembly_Machine_ECOG1X = 168,    /* Cyan Technology eCOG1X */
    System_ELFAssembly_Machine_MAXQ30 = 169,    /* Dallas Semi. MAXQ30 mc */
    System_ELFAssembly_Machine_XIMO16 = 170,    /* New Japan Radio (NJR) 16-bit DSP */
    System_ELFAssembly_Machine_MANIK = 171,    /* M2000 Reconfigurable RISC */
    System_ELFAssembly_Machine_CRAYNV2 = 172,    /* Cray NV2 vector architecture */
    System_ELFAssembly_Machine_RX = 173,    /* Renesas RX */
    System_ELFAssembly_Machine_METAG = 174,    /* Imagination Tech. META */
    System_ELFAssembly_Machine_MCST_ELBRUS = 175,    /* MCST Elbrus */
    System_ELFAssembly_Machine_ECOG16 = 176,    /* Cyan Technology eCOG16 */
    System_ELFAssembly_Machine_CR16 = 177,    /* National Semi. CompactRISC CR16 */
    System_ELFAssembly_Machine_ETPU = 178,    /* Freescale Extended Time Processing Unit */
    System_ELFAssembly_Machine_SLE9X = 179,    /* Infineon Tech. SLE9X */
    System_ELFAssembly_Machine_L10M = 180,    /* Intel L10M */
    System_ELFAssembly_Machine_K10M = 181,    /* Intel K10M */
    /* reserved 182 */
    System_ELFAssembly_Machine_AARCH64 = 183,    /* ARM AARCH64 */
    /* reserved 184 */
    System_ELFAssembly_Machine_AVR32 = 185,    /* Amtel 32-bit microprocessor */
    System_ELFAssembly_Machine_STM8 = 186,    /* STMicroelectronics STM8 */
    System_ELFAssembly_Machine_TILE64 = 187,    /* Tileta TILE64 */
    System_ELFAssembly_Machine_TILEPRO = 188,    /* Tilera TILEPro */
    System_ELFAssembly_Machine_MICROBLAZE = 189,    /* Xilinx MicroBlaze */
    System_ELFAssembly_Machine_CUDA = 190,    /* NVIDIA CUDA */
    System_ELFAssembly_Machine_TILEGX = 191,    /* Tilera TILE-Gx */
    System_ELFAssembly_Machine_CLOUDSHIELD = 192,    /* CloudShield */
    System_ELFAssembly_Machine_COREA_1ST = 193,    /* KIPO-KAIST Core-A 1st gen. */
    System_ELFAssembly_Machine_COREA_2ND = 194,    /* KIPO-KAIST Core-A 2nd gen. */
    System_ELFAssembly_Machine_ARC_COMPACT2 = 195,    /* Synopsys ARCompact V2 */
    System_ELFAssembly_Machine_OPEN8 = 196,    /* Open8 RISC */
    System_ELFAssembly_Machine_RL78 = 197,    /* Renesas RL78 */
    System_ELFAssembly_Machine_VIDEOCORE5 = 198,    /* Broadcom VideoCore V */
    System_ELFAssembly_Machine_78KOR = 199,    /* Renesas 78KOR */
    System_ELFAssembly_Machine_56800EX = 200,    /* Freescale 56800EX DSC */
    System_ELFAssembly_Machine_BA1 = 201,    /* Beyond BA1 */
    System_ELFAssembly_Machine_BA2 = 202,    /* Beyond BA2 */
    System_ELFAssembly_Machine_XCORE = 203,    /* XMOS xCORE */
    System_ELFAssembly_Machine_MCHP_PIC = 204,    /* Microchip 8-bit PIC(r) */
    /* reserved 205-209 */
    System_ELFAssembly_Machine_KM32 = 210,    /* KM211 KM32 */
    System_ELFAssembly_Machine_KMX32 = 211,    /* KM211 KMX32 */
    System_ELFAssembly_Machine_EMX16 = 212,    /* KM211 KMX16 */
    System_ELFAssembly_Machine_EMX8 = 213,    /* KM211 KMX8 */
    System_ELFAssembly_Machine_KVARC = 214,    /* KM211 KVARC */
    System_ELFAssembly_Machine_CDP = 215,    /* Paneve CDP */
    System_ELFAssembly_Machine_COGE = 216,    /* Cognitive Smart Memory Processor */
    System_ELFAssembly_Machine_COOL = 217,    /* Bluechip CoolEngine */
    System_ELFAssembly_Machine_NORC = 218,    /* Nanoradio Optimized RISC */
    System_ELFAssembly_Machine_CSR_KALIMBA = 219,    /* CSR Kalimba */
    System_ELFAssembly_Machine_Z80 = 220,    /* Zilog Z80 */
    System_ELFAssembly_Machine_VISIUM = 221,    /* Controls and Data Services VISIUMcore */
    System_ELFAssembly_Machine_FT32 = 222,    /* FTDI Chip FT32 */
    System_ELFAssembly_Machine_MOXIE = 223,    /* Moxie processor */
    System_ELFAssembly_Machine_AMDGPU = 224,    /* AMD GPU */
    /* reserved 225-242 */
    System_ELFAssembly_Machine_RISCV = 243,    /* RISC-V */
    /* reserved 244-246 */
    System_ELFAssembly_Machine_BPF = 247,    /* Linux BPF -- in-kernel virtual machine */
    /* reserved 248-251 */
    System_ELFAssembly_Machine_CSKY = 252,    /* C-SKY */

    System_ELFAssembly_Machine_ALPHA = 0x9026,
};

export struct System_Type  System_ELFAssembly_MachineType;

typedef System_UInt32 System_ELFAssembly_ProgramType;
enum {
    System_ELFAssembly_ProgramType_Null,
    System_ELFAssembly_ProgramType_Loadable,
    System_ELFAssembly_ProgramType_Dynamic,
    System_ELFAssembly_ProgramType_Interpreter,
    System_ELFAssembly_ProgramType_AuxiliaryNote,
    System_ELFAssembly_ProgramType_SHLIB,
    System_ELFAssembly_ProgramType_ProgramHeader,
    System_ELFAssembly_ProgramType_ThreadLocalStorage,

    System_ELFAssembly_ProgramType_GNU_EHFRAME = 0x6474e550, 
    System_ELFAssembly_ProgramType_GNU_Stack = 0x6474e551,
    System_ELFAssembly_ProgramType_GNU_ReadOnlyRelocation = 0x6474e552,
    System_ELFAssembly_ProgramType_GNU_PROPERTY	= 0x6474e553,
};

export struct System_Type  System_ELFAssembly_ProgramTypeType;

typedef System_UInt32 System_ELFAssembly_ProgramFlags;
enum {
    System_ELFAssembly_ProgramFlags_None,
    System_ELFAssembly_ProgramFlags_Executable,  /* Segment is executable */
    System_ELFAssembly_ProgramFlags_Writable,  /* Segment is writable */
    System_ELFAssembly_ProgramFlags_Readable = 4,  /* Segment is readable */
};

export struct System_Type  System_ELFAssembly_ProgramFlagsType;

typedef System_UInt32 System_ELFAssembly_SectionType;
enum {
    System_ELFAssembly_SectionType_NULL = 0, /* Section header table entry unused */
    System_ELFAssembly_SectionType_PROGBITS = 1, /* Program data */
    System_ELFAssembly_SectionType_SYMTAB = 2, /* Symbol table */
    System_ELFAssembly_SectionType_STRTAB = 3, /* String table */
    System_ELFAssembly_SectionType_RELA = 4, /* Relocation entries with addends */
    System_ELFAssembly_SectionType_HASH = 5, /* Symbol hash table */
    System_ELFAssembly_SectionType_DYNAMIC = 6, /* Dynamic linking information */
    System_ELFAssembly_SectionType_NOTE = 7, /* Notes */
    System_ELFAssembly_SectionType_NOBITS = 8, /* Program space with no data (bss) */
    System_ELFAssembly_SectionType_REL = 9, /* Relocation entries, no addends */
    System_ELFAssembly_SectionType_SHLIB = 10, /* Reserved */
    System_ELFAssembly_SectionType_DYNSYM = 11, /* Dynamic linker symbol table */
    System_ELFAssembly_SectionType_INIT_ARRAY = 14, /* Array of constructors */
    System_ELFAssembly_SectionType_FINI_ARRAY = 15, /* Array of destructors */
    System_ELFAssembly_SectionType_PREINIT_ARRAY = 16, /* Array of pre-constructors */
    System_ELFAssembly_SectionType_GROUP = 17, /* Section group */
    System_ELFAssembly_SectionType_SYMTAB_SHNDX = 18, /* Extended section indeces */
    System_ELFAssembly_SectionType_NUM = 19, /* Number of defined types.  */
    System_ELFAssembly_SectionType_LOOS = 0x60000000, /* Start OS-specific.  */
    System_ELFAssembly_SectionType_GNU_ATTRIBUTES = 0x6ffffff5, /* Object attributes.  */
    System_ELFAssembly_SectionType_GNU_HASH = 0x6ffffff6, /* GNU-style hash table.  */
    System_ELFAssembly_SectionType_GNU_LIBLIST = 0x6ffffff7, /* Prelink library list */
    System_ELFAssembly_SectionType_CHECKSUM = 0x6ffffff8, /* Checksum for DSO content.  */
    System_ELFAssembly_SectionType_LOSUNW = 0x6ffffffa, /* Sun-specific low bound.  */
    System_ELFAssembly_SectionType_SUNW_move = 0x6ffffffa, 
    System_ELFAssembly_SectionType_SUNW_COMDAT = 0x6ffffffb, 
    System_ELFAssembly_SectionType_SUNW_syminfo = 0x6ffffffc, 
    System_ELFAssembly_SectionType_GNU_verdef = 0x6ffffffd, /* Version definition section.  */
    System_ELFAssembly_SectionType_GNU_verneed = 0x6ffffffe, /* Version needs section.  */
    System_ELFAssembly_SectionType_GNU_versym = 0x6fffffff, /* Version symbol table.  */
    System_ELFAssembly_SectionType_HISUNW = 0x6fffffff, /* Sun-specific high bound.  */
    System_ELFAssembly_SectionType_HIOS = 0x6fffffff, /* End OS-specific type */
    System_ELFAssembly_SectionType_LOPROC = 0x70000000, /* Start of processor-specific */
    System_ELFAssembly_SectionType_HIPROC = 0x7fffffff, /* End of processor-specific */
    System_ELFAssembly_SectionType_LOUSER = 0x80000000, /* Start of application-specific */
    System_ELFAssembly_SectionType_HIUSER = 0x8fffffff, /* End of application-specific */
};

export struct System_Type  System_ELFAssembly_SectionTypeType;

typedef System_UInt64 System_ELFAssembly_SectionFlags;
enum {
    System_ELFAssembly_SectionFlags_None,
    System_ELFAssembly_SectionFlags_Writable,
    System_ELFAssembly_SectionFlags_Alloc,
    System_ELFAssembly_SectionFlags_Executable = 4,
    System_ELFAssembly_SectionFlags_Merge = 16,
    System_ELFAssembly_SectionFlags_Strings = 32,
};

export struct System_Type  System_ELFAssembly_SectionFlagsType;

typedef System_Size System_ELFAssembly_DynamicType;
enum {
    System_ELFAssembly_DynamicType_NULL = 0,    /* Marks end of dynamic section */
    System_ELFAssembly_DynamicType_NEEDED = 1,    /* Name of needed library */
    System_ELFAssembly_DynamicType_PLTRELSZ = 2,    /* Size in bytes of PLT relocs */
    System_ELFAssembly_DynamicType_PLTGOT = 3,    /* Processor defined value */
    System_ELFAssembly_DynamicType_HASH = 4,    /* Address of symbol hash table */
    System_ELFAssembly_DynamicType_STRTAB = 5,    /* Address of string table */
    System_ELFAssembly_DynamicType_SYMTAB = 6,    /* Address of symbol table */
    System_ELFAssembly_DynamicType_RELA = 7,    /* Address of Rela relocs */
    System_ELFAssembly_DynamicType_RELASZ = 8,    /* Total size of Rela relocs */
    System_ELFAssembly_DynamicType_RELAENT = 9,    /* Size of one Rela reloc */
    System_ELFAssembly_DynamicType_STRSZ = 10,    /* Size of string table */
    System_ELFAssembly_DynamicType_SYMENT = 11,    /* Size of one symbol table entry */
    System_ELFAssembly_DynamicType_INIT = 12,    /* Address of init function */
    System_ELFAssembly_DynamicType_FINI = 13,    /* Address of termination function */
    System_ELFAssembly_DynamicType_SONAME = 14,    /* Name of shared object */
    System_ELFAssembly_DynamicType_RPATH = 15,    /* Library search path (deprecated) */
    System_ELFAssembly_DynamicType_SYMBOLIC = 16,    /* Start symbol search here */
    System_ELFAssembly_DynamicType_REL = 17,    /* Address of Rel relocs */
    System_ELFAssembly_DynamicType_RELSZ = 18,    /* Total size of Rel relocs */
    System_ELFAssembly_DynamicType_RELENT = 19,    /* Size of one Rel reloc */
    System_ELFAssembly_DynamicType_PLTREL = 20,    /* Type of reloc in PLT */
    System_ELFAssembly_DynamicType_DEBUG = 21,    /* For debugging; unspecified */
    System_ELFAssembly_DynamicType_TEXTREL = 22,    /* Reloc might modify .text */
    System_ELFAssembly_DynamicType_JMPREL = 23,    /* Address of PLT relocs */
    System_ELFAssembly_DynamicType_BIND_NOW = 24,    /* Process relocations of object */
    System_ELFAssembly_DynamicType_INIT_ARRAY = 25,    /* Array with addresses of init fct */
    System_ELFAssembly_DynamicType_FINI_ARRAY = 26,    /* Array with addresses of fini fct */
    System_ELFAssembly_DynamicType_INIT_ARRAYSZ = 27,    /* Size in bytes of DT_INIT_ARRAY */
    System_ELFAssembly_DynamicType_FINI_ARRAYSZ = 28,    /* Size in bytes of DT_FINI_ARRAY */
    System_ELFAssembly_DynamicType_RUNPATH = 29,    /* Library search path */
    System_ELFAssembly_DynamicType_FLAGS = 30,    /* Flags for the object being loaded */
    System_ELFAssembly_DynamicType_ENCODING = 31,    /* Start of encoded range */
    System_ELFAssembly_DynamicType_PREINIT_ARRAY = 32,    /* Array with addresses of preinit fct*/
    System_ELFAssembly_DynamicType_PREINIT_ARRAYSZ = 33,    /* size in bytes of DT_PREINIT_ARRAY */
    System_ELFAssembly_DynamicType_SYMTAB_SHNDX = 34,    /* Address of SYMTAB_SHNDX section */
    System_ELFAssembly_DynamicType_NUM = 35,    /* Number used */
    System_ELFAssembly_DynamicType_LOOS = 0x6000000d,  /* Start of OS-specific */
    System_ELFAssembly_DynamicType_HIOS = 0x6ffff000,  /* End of OS-specific */
    System_ELFAssembly_DynamicType_LOPROC = 0x70000000,  /* Start of processor-specific */
    System_ELFAssembly_DynamicType_HIPROC = 0x7fffffff,  /* End of processor-specific */
    System_ELFAssembly_DynamicType_MIPSNUM = 0x37,  /* Most used by any processor */
    System_ELFAssembly_DynamicType_PROCNUM = System_ELFAssembly_DynamicType_MIPSNUM,
/* DT_* entries which fall between DT_VALRNGHI & DT_VALRNGLO use the
   Dyn.d_un.d_val field of the Elf*_Dyn structure.  This follows Sun's
   approach.  */
    System_ELFAssembly_DynamicType_VALRNGLO = 0x6ffffd00,
    System_ELFAssembly_DynamicType_GNU_PRELINKED = 0x6ffffdf5,  /* Prelinking timestamp */
    System_ELFAssembly_DynamicType_GNU_CONFLICTSZ = 0x6ffffdf6,  /* Size of conflict section */
    System_ELFAssembly_DynamicType_GNU_LIBLISTSZ = 0x6ffffdf7,  /* Size of library list */
    System_ELFAssembly_DynamicType_CHECKSUM = 0x6ffffdf8,
    System_ELFAssembly_DynamicType_PLTPADSZ = 0x6ffffdf9,
    System_ELFAssembly_DynamicType_MOVEENT = 0x6ffffdfa,
    System_ELFAssembly_DynamicType_MOVESZ = 0x6ffffdfb,
    System_ELFAssembly_DynamicType_FEATURE_1 = 0x6ffffdfc,  /* Feature selection (DTF_*).  */
    System_ELFAssembly_DynamicType_POSFLAG_1 = 0x6ffffdfd,  /* Flags for DT_* entries, effecting
             the following DT_* entry.  */
    System_ELFAssembly_DynamicType_SYMINSZ = 0x6ffffdfe,  /* Size of syminfo table (in bytes) */
    System_ELFAssembly_DynamicType_SYMINENT = 0x6ffffdff,  /* Entry size of syminfo */
    System_ELFAssembly_DynamicType_VALRNGHI = 0x6ffffdff,
#define  System_ELFAssembly_DynamicType_VALTAGINDEX(tag)  (System_ELFAssembly_DynamicType_VALRNGHI - (tag))  /* Reverse order! */
    System_ELFAssembly_DynamicType_VALNUM = 12,

/* DT_* entries which fall between DT_ADDRRNGHI & DT_ADDRRNGLO use the
   Dyn.d_un.d_ptr field of the Elf*_Dyn structure.

   If any adjustment is made to the ELF object after it has been
   built these entries will need to be adjusted.  */
    System_ELFAssembly_DynamicType_ADDRRNGLO = 0x6ffffe00,
    System_ELFAssembly_DynamicType_GNU_HASH = 0x6ffffef5,  /* GNU-style hash table.  */
    System_ELFAssembly_DynamicType_TLSDESC_PLT = 0x6ffffef6,
    System_ELFAssembly_DynamicType_TLSDESC_GOT = 0x6ffffef7,
    System_ELFAssembly_DynamicType_GNU_CONFLICT = 0x6ffffef8,  /* Start of conflict section */
    System_ELFAssembly_DynamicType_GNU_LIBLIST = 0x6ffffef9,  /* Library list */
    System_ELFAssembly_DynamicType_CONFIG = 0x6ffffefa,  /* Configuration information.  */
    System_ELFAssembly_DynamicType_DEPAUDIT = 0x6ffffefb,  /* Dependency auditing.  */
    System_ELFAssembly_DynamicType_AUDIT = 0x6ffffefc,  /* Object auditing.  */
    System_ELFAssembly_DynamicType_PLTPAD = 0x6ffffefd,  /* PLT padding.  */
    System_ELFAssembly_DynamicType_MOVETAB = 0x6ffffefe,  /* Move table.  */
    System_ELFAssembly_DynamicType_SYMINFO = 0x6ffffeff,  /* Syminfo table.  */
    System_ELFAssembly_DynamicType_ADDRRNGHI = 0x6ffffeff,
#define System_ELFAssembly_DynamicType_ADDRTAGIDX(tag)  (System_ELFAssembly_DynamicType_ADDRRNGHI - (tag))  /* Reverse order! */
    System_ELFAssembly_DynamicType_ADDRNUM = 11,

/* The versioning entry types.  The next are defined as part of the GNU extension.  */
    System_ELFAssembly_DynamicType_VERSYM = 0x6ffffff0,

    System_ELFAssembly_DynamicType_RELACOUNT = 0x6ffffff9,
    System_ELFAssembly_DynamicType_RELCOUNT = 0x6ffffffa,

/* These were chosen by Sun.  */
    System_ELFAssembly_DynamicType_FLAGS_1 = 0x6ffffffb,  /* State flags, see DF_1_* below.  */
    System_ELFAssembly_DynamicType_VERDEF = 0x6ffffffc,  /* Address of version definition table */
    System_ELFAssembly_DynamicType_VERDEFNUM = 0x6ffffffd,  /* Number of version definitions */
    System_ELFAssembly_DynamicType_VERNEED = 0x6ffffffe,  /* Address of table with needed versions */
    System_ELFAssembly_DynamicType_VERNEEDNUM = 0x6fffffff,  /* Number of needed versions */
#define System_ELFAssembly_DynamicType_VERSIONTAGIDX(tag)  (System_ELFAssembly_DynamicType_VERNEEDNUM - (tag))  /* Reverse order! */
    System_ELFAssembly_DynamicType_VERSIONTAGNUM = 16,

/* Sun added these machine-independent extensions in the "processor-specific" range.  Be compatible.  */
    System_ELFAssembly_DynamicType_AUXILIARY = 0x7ffffffd,      /* Shared object to load before self */
    System_ELFAssembly_DynamicType_FILTER = 0x7fffffff,      /* Shared object to get values from */
#define System_ELFAssembly_DynamicType_EXTRATAGIDX(tag)  ((System_UInt32) - ((System_UInt32)(tag) << 1 >> 1) - 1)
    System_ELFAssembly_DynamicType_EXTRANUM = 3,
};

export struct System_Type  System_ELFAssembly_DynamicTypeType;

typedef System_UInt8 System_ELFAssembly_SymbolBinding;
enum {
    System_ELFAssembly_SymbolBinding_LOCAL,
    System_ELFAssembly_SymbolBinding_GLOBAL,
    System_ELFAssembly_SymbolBinding_WEAK,
    System_ELFAssembly_SymbolBinding_GNU_UNIQUE = 10,
};

export struct System_Type  System_ELFAssembly_SymbolBindingType;

typedef System_UInt8 System_ELFAssembly_SymbolType;
enum {
    System_ELFAssembly_SymbolType_NULL,
    System_ELFAssembly_SymbolType_OBJECT,
    System_ELFAssembly_SymbolType_FUNCTION,
    System_ELFAssembly_SymbolType_SECTION,
    System_ELFAssembly_SymbolType_FILE,
    System_ELFAssembly_SymbolType_COMMON,
    System_ELFAssembly_SymbolType_TLS,
    System_ELFAssembly_SymbolType_GNU_IFUNC = 10,
};

export struct System_Type  System_ELFAssembly_SymbolTypeType;

typedef System_UInt8 System_ELFAssembly_SymbolVisibility;
enum {
    System_ELFAssembly_SymbolVisibility_DEFAULT,
    System_ELFAssembly_SymbolVisibility_INTERNAL,
    System_ELFAssembly_SymbolVisibility_HIDDEN,
    System_ELFAssembly_SymbolVisibility_PROTECTED,
};

export struct System_Type  System_ELFAssembly_SymbolVisibilityType;

typedef System_UInt16 System_ELFAssembly_SpecialSectionIndex;
enum {
    System_ELFAssembly_SpecialSectionIndex_Undefined,
    System_ELFAssembly_SpecialSectionIndex_Absolute = 0xfff1,
    System_ELFAssembly_SpecialSectionIndex_Common = 0xfff2,
    System_ELFAssembly_SpecialSectionIndex_ExtraIndex = 0xffff,
};

export struct System_Type  System_ELFAssembly_SpecialSectionIndexType;

/* AMD x86-64 relocations.  */
typedef System_UInt32 System_ELFAssembly_AMD64Relocation;
enum {
    System_ELFAssembly_AMD64_NONE = 0,  /* No reloc */
    System_ELFAssembly_AMD64_64 = 1,  /* Direct 64 bit  */
    System_ELFAssembly_AMD64_PC32 = 2,  /* PC relative 32 bit signed */
    System_ELFAssembly_AMD64_GOT32 = 3,  /* 32 bit GOT entry */
    System_ELFAssembly_AMD64_PLT32 = 4,  /* 32 bit PLT address */
    System_ELFAssembly_AMD64_COPY = 5,  /* Copy symbol at runtime */
    System_ELFAssembly_AMD64_GLOB_DAT = 6,  /* Create GOT entry */
    System_ELFAssembly_AMD64_JUMP_SLOT = 7,  /* Create PLT entry */
    System_ELFAssembly_AMD64_RELATIVE = 8,  /* Adjust by program base */
    System_ELFAssembly_AMD64_GOTPCREL = 9,  /* 32 bit signed PC relative offset to GOT */
    System_ELFAssembly_AMD64_32 = 10,  /* Direct 32 bit zero extended */
    System_ELFAssembly_AMD64_32S = 11,  /* Direct 32 bit sign extended */
    System_ELFAssembly_AMD64_16 = 12,  /* Direct 16 bit zero extended */
    System_ELFAssembly_AMD64_PC16 = 13,  /* 16 bit sign extended pc relative */
    System_ELFAssembly_AMD64_8 = 14,  /* Direct 8 bit sign extended  */
    System_ELFAssembly_AMD64_PC8 = 15,  /* 8 bit sign extended pc relative */
    System_ELFAssembly_AMD64_DTPMOD64 = 16,  /* ID of module containing symbol */
    System_ELFAssembly_AMD64_DTPOFF64 = 17,  /* Offset in module's TLS block */
    System_ELFAssembly_AMD64_TPOFF64 = 18,  /* Offset in initial TLS block */
    System_ELFAssembly_AMD64_TLSGD = 19,  /* 32 bit signed PC relative offset to two GOT entries for GD symbol */
    System_ELFAssembly_AMD64_TLSLD = 20,  /* 32 bit signed PC relative offset to two GOT entries for LD symbol */
    System_ELFAssembly_AMD64_DTPOFF32 = 21,  /* Offset in TLS block */
    System_ELFAssembly_AMD64_GOTTPOFF = 22,  /* 32 bit signed PC relative offset to GOT entry for IE symbol */
    System_ELFAssembly_AMD64_TPOFF32 = 23,  /* Offset in initial TLS block */
    System_ELFAssembly_AMD64_PC64 = 24,  /* PC relative 64 bit */
    System_ELFAssembly_AMD64_GOTOFF64 = 25,  /* 64 bit offset to GOT */
    System_ELFAssembly_AMD64_GOTPC32 = 26,  /* 32 bit signed pc relative offset to GOT */
    System_ELFAssembly_AMD64_GOT64 = 27,  /* 64-bit GOT entry offset */
    System_ELFAssembly_AMD64_GOTPCREL64 = 28,  /* 64-bit PC relative offset to GOT entry */
    System_ELFAssembly_AMD64_GOTPC64 = 29,  /* 64-bit PC relative offset to GOT */
    System_ELFAssembly_AMD64_GOTPLT64 = 30,  /* like GOT64, says PLT entry needed */
    System_ELFAssembly_AMD64_PLTOFF64 = 31,  /* 64-bit GOT relative offset to PLT entry */
    System_ELFAssembly_AMD64_SIZE32 = 32,  /* Size of symbol plus 32-bit addend */
    System_ELFAssembly_AMD64_SIZE64 = 33,  /* Size of symbol plus 64-bit addend */
    System_ELFAssembly_AMD64_GOTPC32_TLSDESC = 34,  /* GOT offset for TLS descriptor.  */
    System_ELFAssembly_AMD64_TLSDESC_CALL = 35,  /* Marker for call through TLS descriptor.  */
    System_ELFAssembly_AMD64_TLSDESC = 36,  /* TLS descriptor.  */
    System_ELFAssembly_AMD64_IRELATIVE = 37,  /* Adjust indirectly by program base */
    System_ELFAssembly_AMD64_RELATIVE64 = 38,  /* 64-bit adjust by program base */
    /* 39 Reserved was R_AMD64_PC32_BND */
    /* 40 Reserved was R_AMD64_PLT32_BND */
    System_ELFAssembly_AMD64_GOTPCRELX = 41,  /* Load from 32 bit signed pc relative offset to GOT entry without REX prefix, relaxable.  */
    System_ELFAssembly_AMD64_REX_GOTPCRELX = 42,  /* Load from 32 bit signed pc relative offset to GOT entry with REX prefix, relaxable.  */
    /* System_ELFAssembly_AMD64_NUM = 43 */
};

export struct System_Type  System_ELFAssembly_AMD64RelocationType;

#endif
#if !defined(have_System_ELF32Assembly)
#define have_System_ELF32Assembly

export struct System_Type  System_ELF32AssemblyType;

typedef struct System_ELF32Assembly_Header {
    struct {
        System_UInt8  magic[4];
        System_UInt8  class;
        System_UInt8  endianess;
        System_UInt8  elfVersion;
        System_UInt8  abi;
        System_UInt8  abiVersion;
        System_UInt8  __reserved[7];
    };
    System_UInt16    type;               /* Object file type */
    System_UInt16    machine;            /* Architecture */
    System_UInt32    version;            /* Object file version */
    System_UInt32    entryPoint;              /* Entry point virtual address */
    System_UInt32    programHeaderOffset;              /* Program header table file offset */
    System_UInt32    sectionHeaderOffset;              /* Section header table file offset */
    System_UInt32    processorFlags;              /* Processor-specific flags */
    System_UInt16    headerSize;             /* ELF header size in bytes */
    System_UInt16    programHeaderSize;          /* Program header table entry size */
    System_UInt16    programHeaderCount;              /* Program header table entry count */
    System_UInt16    sectionHeaderSize;          /* Section header table entry size */
    System_UInt16    sectionHeaderCount;              /* Section header table entry count */
    System_UInt16    stringSectionIndex;           /* Section header string table index */
} * System_ELF32Assembly_Header;

export struct System_Type  System_ELF32Assembly_HeaderType;

typedef struct System_ELF32Assembly_ProgramHeader {
  System_UInt32  type;    /* Program type */
  System_UInt32  flags;    /* Program flags */
  System_UInt32  offset;    /* Program file offset */
  System_UInt32  virtualAddress;    /* Program virtual address */
  System_UInt32  physicalAddress;    /* Program physical address */
  System_UInt32  fileSize;    /* Program size in file */
  System_UInt32  memorySize;    /* Program size in memory */
  System_UInt32  alignment;    /* Program alignment */
} * System_ELF32Assembly_ProgramHeader;

export struct System_Type  System_ELF32Assembly_ProgramHeaderType;

typedef struct System_ELF32Assembly_SectionHeader {
  System_UInt32  name;        /* Section name (string tbl index) */
  System_UInt32  type;        /* Section type */
  System_UInt32  flags;        /* Section flags */
  System_UInt32  address;        /* Section virtual address at execution */
  System_UInt32  offset;     /* Section file offset */
  System_UInt32  size;        /* Section size in bytes */
  System_UInt32  link;        /* Link to another section */
  System_UInt32  info;        /* Additional section information */
  System_UInt32  alignment;        /* Section alignment */
  System_UInt32  entrySize;        /* Entry size if section holds table */
} * System_ELF32Assembly_SectionHeader;

export struct System_Type  System_ELF32Assembly_SectionHeaderType;


typedef struct System_ELF32Assembly_Symbol {
    System_UInt32  name;    /* Symbol name (string tbl index) */
    System_UInt32  value;    /* Symbol value */
    System_UInt32  size;    /* Symbol size */
    System_UInt8  info;    /* Symbol type and binding */
    System_UInt8  other;    /* Symbol visibility */
    System_UInt16  sectionIndex;    /* Section index */
} * System_ELF32Assembly_Symbol;

export struct System_Type  System_ELF32Assembly_SymbolType;

typedef struct System_ELF32Assembly_DynamicEntry {
    System_Int32  tag;      /* Dynamic entry type */
    System_UInt32  value;      /* value */
} * System_ELF32Assembly_DynamicEntry;

export struct System_Type  System_ELF32Assembly_DynamicEntryType;

#define System_ELF32Assembly_Relocation_SYMBOL(i) ( (i) >> 8 )
#define System_ELF32Assembly_Relocation_TYPE(i)   ( (System_UInt8)((i) & 0xff) )
#define System_ELF32Assembly_Relocation_INFO(s,t) ( ((s) << 8) + ((System_UInt8)((t) & 0xff)) )

#endif
#if !defined(have_System_ELF64Assembly)
#define have_System_ELF64Assembly

typedef struct System_ELF64Assembly_Header {
    struct {
        System_UInt8  magic[4];
        System_UInt8  class;
        System_UInt8  endianess;
        System_UInt8  elfVersion;
        System_UInt8  abi;
        System_UInt8  abiVersion;
        System_UInt8  __reserved[7];
    };
    System_UInt16    type;               /* Object file type */
    System_UInt16    machine;            /* Architecture */
    System_UInt32    version;            /* Object file version */
    System_UInt64    entryPoint;              /* Entry point virtual address */
    System_UInt64    programHeaderOffset;              /* Program header table file offset */
    System_UInt64    sectionHeaderOffset;              /* Section header table file offset */
    System_UInt32    processorFlags;              /* Processor-specific flags */
    System_UInt16    size;             /* ELF header size in bytes */
    System_UInt16    programHeaderSize;          /* Program header table entry size */
    System_UInt16    programHeaderCount;              /* Program header table entry count */
    System_UInt16    sectionHeaderSize;          /* Section header table entry size */
    System_UInt16    sectionHeaderCount;              /* Section header table entry count */
    System_UInt16    stringSectionIndex;           /* Section header string table index */
} * System_ELF64Assembly_Header;

export struct System_Type  System_ELF64Assembly_HeaderType;

typedef struct System_ELF64Assembly_ProgramHeader {
  System_UInt32  type;    /* Program type */
  System_UInt32  flags;    /* Program flags */
  System_UInt64  offset;    /* Program file offset */
  System_UInt64  virtualAddress;    /* Program virtual address */
  System_UInt64  physicalAddress;    /* Program physical address */
  System_UInt64  fileSize;    /* Program size in file */
  System_UInt64  memorySize;    /* Program size in memory */
  System_UInt64  alignment;    /* Program alignment */
} * System_ELF64Assembly_ProgramHeader;

export struct System_Type  System_ELF64Assembly_ProgramHeaderType;

typedef struct System_ELF64Assembly_SectionHeader {
  System_UInt32  name;        /* Section name (string tbl index) */
  System_UInt32  type;        /* Section type */
  System_UInt64  flags;        /* Section flags */
  System_UInt64  virtualAddress;        /* Section virtual address at execution */
  System_UInt64  offset;     /* Section file offset */
  System_UInt64  size;        /* Section size in bytes */
  System_UInt32  link;        /* Link to another section */
  System_UInt32  info;        /* Additional section information */
  System_UInt64  alignment;        /* Section alignment */
  System_UInt64  entrySize;        /* Entry size if section holds table */
} * System_ELF64Assembly_SectionHeader;

export struct System_Type  System_ELF64Assembly_SectionHeaderType;

typedef struct System_ELF64Assembly_Symbol {
    System_UInt32  name;    /* Symbol name (string tbl index) */
    System_UInt8  info;    /* Symbol type and binding */
    System_UInt8  other;    /* Symbol visibility */
    System_UInt16  sectionIndex;    /* Section index */
    System_UInt64  value;    /* Symbol value */
    System_UInt64  size;    /* Symbol size */
} * System_ELF64Assembly_Symbol;

export struct System_Type  System_ELF64Assembly_SymbolType;

typedef struct System_ELF64Assembly_DynamicEntry {
    System_Int64  tag;      /* Dynamic entry type */
    System_UInt64  value;      /* value */
} * System_ELF64Assembly_DynamicEntry;

export struct System_Type  System_ELF64Assembly_DynamicEntryType;

typedef struct System_ELF64Assembly_Relocation {
    System_UInt64  offset;
    System_UInt32  type;
    System_UInt32  symbol;
    System_Int64  addend;
} * System_ELF64Assembly_Relocation;

export struct System_Type  System_ELF64Assembly_RelocationType;

typedef struct System_ELF64Assembly {
    struct System_Object base;

    System_String8 name;

    System_String8 buffer;

    System_ELF64Assembly_Header header;

    System_ELF64Assembly_ProgramHeader programs;

    System_ELF64Assembly_SectionHeader sections;
    System_String8 sectionsStrings;

    System_Size symbolsCount;
    System_ELF64Assembly_Symbol symbols;
    System_String8 symbolStrings;

    System_Size dynamicsCount;
    System_ELF64Assembly_DynamicEntry dynamics;

    System_Size dynamicSymbolsCount;
    System_ELF64Assembly_Symbol dynamicSymbols;
    System_String8 dynamicStrings;

    System_Size neededCount;
    System_String8 needed[8];

    System_Var link;

    System_Size GOT_relocationCount;
    System_ELF64Assembly_Relocation GOT_relocation;

    System_Size PLT_relocationCount;
    System_ELF64Assembly_Relocation PLT_relocation;

    System_Size * PLT;

    System_Size threadStorageSize;
    System_Var threadStorage;
    System_Size threadStorageOffset;

} * System_ELF64Assembly;

export struct System_Type  System_ELF64AssemblyType;

export System_ELF64Assembly System_ELF64Assembly_loaded[64];
export System_Size System_ELF64Assembly_loadedCount;

export System_ELF64Assembly  new_System_ELF64Assembly();
export void System_ELF64Assembly_read(System_ELF64Assembly assembly, System_String8 name);
export void System_ELF64Assembly_read__print(System_ELF64Assembly assembly, System_String8 name, System_Bool print);
export void System_ELF64Assembly_link(System_ELF64Assembly assembly);
export void System_ELF64Assembly_relocate(System_ELF64Assembly assembly, System_ELF64Assembly_Relocation relocation);
import System_Var System_ELF64Assembly_jump(System_ELF64Assembly assembly, System_UInt64 relocationOffset);
export System_Var System_ELF64Assembly_resolve(System_ELF64Assembly assembly, System_UInt64 relocationOffset);
export System_ELF64Assembly_Symbol System_ELF64Assembly_getSymbol(System_String8 name, System_ELF64Assembly * out_assembly);
export System_ELF64Assembly_Symbol System_ELF64Assembly_getDynamicSymbol(System_String8 name, System_ELF64Assembly * out_assembly);
export System_ELF64Assembly_SectionHeader System_ELF64Assembly_getSection(System_ELF64Assembly assembly, System_String8 name);

export System_Var System_ELF64Assembly_createThread(void);

export System_String8 System_ELFAssembly_AMD64_toString(System_UInt32 value);
export System_String8 System_ELFAssembly_SymbolBinding_toString(System_UInt8 value);
export System_String8 System_ELFAssembly_SymbolType_toString(System_UInt8 value);
export System_String8 System_ELFAssembly_DynamicType_toString(System_ELFAssembly_DynamicType value);
export System_String8 System_ELFAssembly_ProgramType_toString(System_ELFAssembly_ProgramType value);
export System_String8 System_ELFAssembly_AssemblyType_toString(System_ELFAssembly_AssemblyType value);
export System_String8 System_ELFAssembly_ABI_toString(System_ELFAssembly_ABI value);
export System_String8 System_ELFAssembly_Machine_toString(System_ELFAssembly_Machine value);

#endif
#if !defined(have_System_ELFAssembly)
#define have_System_ELFAssembly

#define System_ELFAssembly_Symbol_BIND(i)   ( (i) >> 4 )
#define System_ELFAssembly_Symbol_TYPE(i)   ( (i) & 0xf )
#define System_ELFAssembly_Symbol_INFO(b,t) ( ((b) << 4) + ((t) & 0xf ) )

#if System_Size_Bits == 32
#warning TODO: System_Size_Bits == 32
#define System_ELFAssembly  System_ELF32Assembly
#define System_ELFAssemblyType  System_ELF32AssemblyType
#define System_ELFAssembly_Header  System_ELF32Assembly_Header
#define System_ELFAssembly_ProgramHeader  System_ELF32Assembly_ProgramHeader
#define System_ELFAssembly_SectionHeader  System_ELF32Assembly_SectionHeader
#define System_ELFAssembly_Symbol  System_ELF32Assembly_Symbol
#define System_ELFAssembly_DynamicEntry  System_ELF32Assembly_DynamicEntry
#define System_ELFAssembly_Relocation_SYMBOL  System_ELF32Assembly_Relocation_SYMBOL
#define System_ELFAssembly_Relocation_TYPE  System_ELF32Assembly_Relocation_TYPE
#define System_ELFAssembly_Relocation_INFO  System_ELF32Assembly_Relocation_INFO

#else /* if System_Size_Bits == 64 */
#define System_ELFAssembly  System_ELF64Assembly
#define System_ELFAssemblyType  System_ELF64AssemblyType
#define System_ELFAssembly_Header  System_ELF64Assembly_Header
#define System_ELFAssembly_ProgramHeader  System_ELF64Assembly_ProgramHeader
#define System_ELFAssembly_SectionHeader  System_ELF64Assembly_SectionHeader
#define System_ELFAssembly_Symbol  System_ELF64Assembly_Symbol
#define System_ELFAssembly_DynamicEntry  System_ELF64Assembly_DynamicEntry
#define System_ELFAssembly_Relocation_SYMBOL  System_ELF64Assembly_Relocation_SYMBOL
#define System_ELFAssembly_Relocation_TYPE  System_ELF64Assembly_Relocation_TYPE
#define System_ELFAssembly_Relocation_INFO  System_ELF64Assembly_Relocation_INFO
#endif

#if defined(using_System)
#define ELFAssembly  System_ELFAssembly
#define ELFAssemblyType  System_ELFAssemblyType
#define ELFAssembly_Header  System_ELFAssembly_Header
#define ELFAssembly_HeaderType  System_ELFAssembly_HeaderType
#endif
#endif