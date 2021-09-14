# 生成的相关参数
SERVER_CPP_SRCS += \
	../server.cpp

SERVER_OBJS += \
	./server.o 

SERVER_CPP_DEPS += \
	./server.d 

CLIENT_CPP_SRCS += \
	../client.cpp

CLIENT_OBJS += \
	./client.o 

CLIENT_CPP_DEPS += \
	./client.d 

# 根据.cpp文件生成.o文件
%.o: ../%.cpp
	@echo '创建目标: $<'
	g++ -O0 -g3 -Wall -DWITH_NONAMESPACES -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo '完成创建目标: $<'
	@echo "\n"
