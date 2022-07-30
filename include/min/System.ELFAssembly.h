/* Gemeinfrei. Public Domain. */
#if !defined(have_System_Type)
#include <min/System.Type.h>
#endif

#if !defined(have_System_ELFAssembly)
#define have_System_ELFAssembly

export System_STRING8 System_ELFAssembly_Magic;
#define System_ELFAssembly_Magic_VALUE  "\177ELF"

#define System_ELFAssembly_Header_MaxSize  262144

typedef unsigned System_ELFAssembly_Class;
enum {
    System_ELFAssembly_Class_None,
    System_ELFAssembly_Class_32,
    System_ELFAssembly_Class_64,
};

typedef unsigned System_ELFAssembly_Endianess;
enum {
    System_ELFAssembly_Endianess_None,
    System_ELFAssembly_Endianess_Little,
    System_ELFAssembly_Endianess_Big,
};

typedef unsigned System_ELFAssembly_Version;
enum {
    System_ELFAssembly_Version_None,
    System_ELFAssembly_Version_Current,
};

typedef unsigned System_ELFAssembly_ABI;
enum {
    System_ELFAssembly_ABI_None,
    System_ELFAssembly_ABI_SysV,
    System_ELFAssembly_ABI_HPUX,
    System_ELFAssembly_ABI_NetBSD,
    System_ELFAssembly_ABI_GNU,
    System_ELFAssembly_ABI_Linux = System_ELFAssembly_ABI_GNU,
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

typedef unsigned System_ELFAssembly_AssemblyType;
enum {
    System_ELFAssembly_AssemblyType_None,
    System_ELFAssembly_AssemblyType_Relocatable,
    System_ELFAssembly_AssemblyType_Executable,
    System_ELFAssembly_AssemblyType_Shared,
    System_ELFAssembly_AssemblyType_Core,
    System_ELFAssembly_AssemblyType_OperatingSystemSpecificLow = 0xfe00,
    System_ELFAssembly_AssemblyType_OperatingSystemSpecificHigh = 0xfeff,
    System_ELFAssembly_AssemblyType_ProcessorSpecificLow = 0xff00,
    System_ELFAssembly_AssemblyType_ProcessorSpecificHigh = 0xffff,
};

typedef unsigned System_ELFAssembly_Machine;
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
    System_ELFAssembly_Machine_X86_64 = 62,    /* AMD x86-64 architecture */
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

typedef unsigned System_ELFAssembly_ProgramType;
enum {
    System_ELFAssembly_ProgramType_Null,
    System_ELFAssembly_ProgramType_Loadable,
    System_ELFAssembly_ProgramType_Dynamic,
    System_ELFAssembly_ProgramType_Interpreter,
    System_ELFAssembly_ProgramType_AuxiliaryNote,
    System_ELFAssembly_ProgramType_SHLIB,
    System_ELFAssembly_ProgramType_ProgramHeader,
    System_ELFAssembly_ProgramType_ThreadLocalStorage,
    System_ELFAssembly_ProgramType_NUMBER,
    /* System_ELFAssembly_ProgramType_OSSpecificLow = 0x60000000, */
    System_ELFAssembly_ProgramType_GNU_EHFRAME = 0x6474e550,
    System_ELFAssembly_ProgramType_GNU_Stack = 0x6474e551,
    System_ELFAssembly_ProgramType_GNU_ReadOnlyRelocation = 0x6474e552,
};

typedef unsigned System_ELFAssembly_ProgramFlags;
enum {
    None,
    Executable,  /* Segment is executable */
    Writable,  /* Segment is writable */
    Readable = 4,  /* Segment is readable */
    OSSpecific = 0x0ff00000,  /* OS-specific */
    ProcessorSpecific = 0xf0000000,  /* Processor-specific */
};

#if System_Size_Width == 32
#define System_ELFAssembly  System_ELF32Assembly
#define System_ELFAssemblyType  System_ELF32AssemblyType
#define System_ELFAssembly_Header  System_ELF32Assembly_Header
#define System_ELFAssembly_ProgramHeader  System_ELF32Assembly_ProgramHeader
#define System_ELFAssembly_SectionHeader  System_ELF32Assembly_SectionHeader

#else /* if System_Size_Width == 64 */
#define System_ELFAssembly  System_ELF64Assembly
#define System_ELFAssemblyType  System_ELF64AssemblyType
#define System_ELFAssembly_Header  System_ELF64Assembly_Header
#define System_ELFAssembly_ProgramHeader  System_ELF64Assembly_ProgramHeader
#define System_ELFAssembly_SectionHeader  System_ELF64Assembly_SectionHeader
#endif

#if defined(using_System)
#define ELFAssembly  System_ELFAssembly
#define ELFAssemblyType  System_ELFAssemblyType
#define ELFAssembly_Header  System_ELFAssembly_Header
#define ELFAssembly_HeaderType  System_ELFAssembly_HeaderType
#endif
#endif
#if !defined(have_System_ELF32Assembly)
#define have_System_ELF32Assembly

export struct System_Type  System_ELF32AssemblyType;

typedef struct System_ELF32Assembly_Header {
    struct {
        System_Char8  magic[4];
        System_Char8  class;
        System_Char8  endianess;
        System_Char8  elfVersion;
        System_Char8  abi;
        System_Char8  abiVersion;
        System_Char8  __reserved[7];
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
  System_UInt32  sectionSize;        /* Section size in bytes */
  System_UInt32  link;        /* Link to another section */
  System_UInt32  info;        /* Additional section information */
  System_UInt32  alignment;        /* Section alignment */
  System_UInt32  entrySize;        /* Entry size if section holds table */
} * System_ELF32Assembly_SectionHeader;

export struct System_Type  System_ELF32Assembly_SectionHeaderType;

#endif
#if !defined(have_System_ELF64Assembly)
#define have_System_ELF64Assembly

export struct System_Type  System_ELF64AssemblyType;

typedef struct System_ELF64Assembly_Header {
    struct {
        System_Char8  magic[4];
        System_Char8  class;
        System_Char8  endianess;
        System_Char8  elfVersion;
        System_Char8  abi;
        System_Char8  abiVersion;
        System_Char8  __reserved[7];
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
  System_UInt64  address;        /* Section virtual address at execution */
  System_UInt64  offset;     /* Section file offset */
  System_UInt64  sectionSize;        /* Section size in bytes */
  System_UInt32  link;        /* Link to another section */
  System_UInt32  info;        /* Additional section information */
  System_UInt64  alignment;        /* Section alignment */
  System_UInt64  entrySize;        /* Entry size if section holds table */
} * System_ELF64Assembly_SectionHeader;

export struct System_Type  System_ELF64Assembly_SectionHeaderType;

#endif