CC = gcc
CFWK_DIR = ../../cFWK/
target =  demo3d

C_FLAGS=
LD_FLAGS=-lSDL2
src=  $(CFWK_DIR)/cf_test/cf_test.c \
	  $(CFWK_DIR)/cf_allocator/cf_allocator_simple.c \
	  $(CFWK_DIR)/cf_collection/cf_list.c \
	  $(CFWK_DIR)/cf_collection/cf_string.c \
	  $(CFWK_DIR)/cf_collection/cf_iterator.c \
	  $(CFWK_DIR)/cf_collection/cf_hash.c \
	  $(CFWK_DIR)/cf_iostream/cf_iostream.c \
	  $(CFWK_DIR)/cf_logger/cf_logger.c \
	  $(CFWK_DIR)/cf_module/cf_module.c \
	  $(CFWK_DIR)/cf_thread/cf_thread.c \
	  $(CFWK_DIR)/cf_factory/cf_factory.c \
	  $(CFWK_DIR)/cf_factory/cf_element.c \
	  $(CFWK_DIR)/cf_factory/cf_pad.c \
	  $(CFWK_DIR)/cf_factory/cf_element_class.c \
	  $(CFWK_DIR)/cf_test_case/cf_list_test.c \
	  $(CFWK_DIR)/cf_test_case/cf_module_test.c \
	  ../cf_3d_factory.c \
	  ../cf_sdlsink.c \
	  ../cf_triangle_painter.c \
	  main.c

obj := $(src:c=o)

all:	$(obj)
	$(CC)	-g $(C_FLAGS) -I$(CFWK_DIR) $^ $(LD_FLAGS) -o $(target)
$(obj): %.o : %.c
	$(CC) -g $(C_FLAGS) -I$(CFWK_DIR) -o $@ -c $^
clean:
	rm $(obj) $(target)
