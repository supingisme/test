#文件：makefile
RM := rm -rf

# 引入相关的生成文件
-include sources.mk
-include subdir.mk
-include soap/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
  ifneq ($(strip $(C++_DEPS)),)
    -include $(C++_DEPS)
  endif
  ifneq ($(strip $(C_DEPS)),)
    -include $(C_DEPS)
  endif
  ifneq ($(strip $(CC_DEPS)),)
    -include $(CC_DEPS)
  endif
  ifneq ($(strip $(SERVER_CPP_DEPS)),)
    -include $(SERVER_CPP_DEPS)
  endif
  ifneq ($(strip $(CLIENT_CPP_DEPS)),)
    -include $(CLIENT_CPP_DEPS)
  endif
  ifneq ($(strip $(CXX_DEPS)),)
    -include $(CXX_DEPS)
  endif
  ifneq ($(strip $(C_UPPER_DEPS)),)
    -include $(C_UPPER_DEPS)
  endif
endif

# 生成目标
all: server client

# 相关工具
server: $(SERVER_OBJS) $(USER_OBJS)
	@echo '创建目标: $@'
	g++  -o"server" $(SERVER_OBJS) $(USER_OBJS) $(LIBS)
	@echo '完成创建目标: $@'
	@echo "\n"

client: $(CLIENT_OBJS) $(USER_OBJS)
	@echo '创建目标: $@'
	g++  -o"client" $(CLIENT_OBJS) $(USER_OBJS) $(LIBS)
	@echo '完成创建目标: $@'
	@echo "\n"

# 清空临时文件
clean:
	-$(RM) $(SERVER_OBJS)$(CLIENT_OBJS)$(C++_DEPS)$(C_DEPS)$(CC_DEPS)$(SERVER_CPP_DEPS)$(CLIENT_CPP_DEPS)$(EXECUTABLES)$(CXX_DEPS)$(C_UPPER_DEPS)
	-@echo "\n"
cleanall:
	-$(RM) $(SERVER_OBJS)$(CLIENT_OBJS)$(C++_DEPS)$(C_DEPS)$(CC_DEPS)$(SERVER_CPP_DEPS)$(CLIENT_CPP_DEPS)$(EXECUTABLES)$(CXX_DEPS)$(C_UPPER_DEPS) server client
	-@echo "\n"
cleanexe:
	-$(RM) server client
	-@echo "\n"

.PHONY: all clean dependents cleanall cleanexe
