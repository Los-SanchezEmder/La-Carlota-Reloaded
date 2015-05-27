#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_DLIB_EXT=so
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/Date.o \
	${OBJECTDIR}/PortSerial/PortSerial.o \
	${OBJECTDIR}/Sensor/Acelerometro/Acelerometro.o \
	${OBJECTDIR}/Sensor/Dato.o \
	${OBJECTDIR}/Sensor/Sensor.o \
	${OBJECTDIR}/Sensor/Temperatura/Temperatura.o \
	${OBJECTDIR}/main.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/frdm_class

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/frdm_class: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/frdm_class ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/Date.o: Date.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Date.o Date.cpp

${OBJECTDIR}/PortSerial/PortSerial.o: PortSerial/PortSerial.cpp 
	${MKDIR} -p ${OBJECTDIR}/PortSerial
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/PortSerial/PortSerial.o PortSerial/PortSerial.cpp

${OBJECTDIR}/Sensor/Acelerometro/Acelerometro.o: Sensor/Acelerometro/Acelerometro.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sensor/Acelerometro
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Sensor/Acelerometro/Acelerometro.o Sensor/Acelerometro/Acelerometro.cpp

${OBJECTDIR}/Sensor/Dato.o: Sensor/Dato.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sensor
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Sensor/Dato.o Sensor/Dato.cpp

${OBJECTDIR}/Sensor/Sensor.o: Sensor/Sensor.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sensor
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Sensor/Sensor.o Sensor/Sensor.cpp

${OBJECTDIR}/Sensor/Temperatura/Temperatura.o: Sensor/Temperatura/Temperatura.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sensor/Temperatura
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Sensor/Temperatura/Temperatura.o Sensor/Temperatura/Temperatura.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/frdm_class

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
