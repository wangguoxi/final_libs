-include ../common/Makefile.common

TARGET = libfev.a

INCLUDE_FILES = fev.h \
		fev_timer.h \
		fev_buff.h \
		fev_conn.h \
		fev_listener.h \
		fev_timer_service.h \
		fev_tmsvc_types.h

AR = ar -rcs
INC = -I../
LL = 
LIBS = 

SRCS = fev.c \
	   fev_timer.c \
	   fev_buff.c \
	   fev_conn.c \
	   fev_listener.c \
	   fev_tmsvc_modules.c \
	   fev_timer_service.c \
	   fev_tmsvc_sl_mod.c

DEPS = $(patsubst %.c,%.d,$(SRCS))
OBJS = $(patsubst %.c,%.o,$(SRCS))

CFLAGS += $(EXT_FLAGS)
CFLAGS +=

all:$(TARGET)
$(TARGET):$(OBJS) $(DEPS)
	$(AR) $(TARGET) $(OBJS)

%.d:%.c
	$(CC) $(INC) -MM $< > $@
%.o:%.c 
	$(CC) $(CFLAGS) $(INC) -c $< 

install:
	-(test -d $(INSTALL_PATH) || mkdir -p $(INSTALL_PATH) )
	-(test -d $(INSTALL_PATH)/$(INCLUDE_PATH) || mkdir -p $(INSTALL_PATH)/$(INCLUDE_PATH) )
	-(test -d $(INSTALL_PATH)/$(LIBS_PATH) || mkdir $(INSTALL_PATH)/$(LIBS_PATH) )
	cp $(INCLUDE_FILES) $(INSTALL_PATH)/$(INCLUDE_PATH)
	cp $(TARGET) $(INSTALL_PATH)/$(LIBS_PATH)

.PHONY:clean
clean:
	rm -f $(DEPS) $(OBJS) $(TARGET)

help:
	@echo "The information represents in the program:"
	@echo "Final executable name: $(TARGET)"
	@echo "Source files: $(SRCS)"
	@echo "Object files: $(OBJS)"
depend:$(DEPS)
	@echo "Dependencies are now up-to-date"
-include $(DEPS)
