CC = gcc

TARGET = main main1 vma
all: $(TARGET)

main : test.o rbtree.o
	$(CC) -o $@ $^

main1 : test1.o rbtree.o
	$(CC) -o $@ $^

vma : vma.o rbtree.o
	$(CC) -o $@ $^

%.o : %.c
	    $(CC) -c $^ -o $@

.PHONY : clean
clean :
	 rm -f *.o
	 rm -f $(TARGET)
