# 生成的相关参数
SERVER_CPP_SRCS += \
	../soap/soapC.cpp \
	../soap/soapcalcService.cpp \
  /home/gsoap-2.8/gsoap/stdsoap2.cpp

SERVER_OBJS += \
  ./soap/soapC.o \
  ./soap/soapcalcService.o \
  ./soap/stdsoap2.o

SERVER_CPP_DEPS += \
  ./soap/soapC.d \
  ./soap/soapcalcService.d \
  ./soap/stdsoap2.d 

CLIENT_CPP_SRCS += \
  ../soap/soapC.cpp \
  ../soap/soapcalcProxy.cpp \
  /home/gsoap-2.8/gsoap/stdsoap2.cpp

CLIENT_OBJS += \
  ./soap/soapC.o \
  ./soap/soapcalcProxy.o \
  ./soap/stdsoap2.o

CLIENT_CPP_DEPS += \
  ./soap/soapC.d \
  ./soap/soapcalcProxy.d \
  ./soap/stdsoap2.d 

# 根据.cpp文件生成.o文件
soap/%.o: ../soap/%.cpp
	@echo '创建目标: $<'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo '完成创建目标: $<'
	@echo "\n"

soap/%.o:/home/gsoap-2.8/gsoap/%.cpp
	@echo '创建目标: $<'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo '完成创建目标: $<'
	@echo "\n"
