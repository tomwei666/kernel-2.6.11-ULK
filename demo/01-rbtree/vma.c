#include <stdio.h>
#include <stdlib.h>
#include "rbtree.h"
#include "vma.h"

/*void print_rbtree(struct rb_root *tree)*/
/*{*/
		/*struct rb_node *node;*/
			
			/*for (node = rb_first(tree); node; node = rb_next(node))*/
					/*printf("%d ", rb_entry(node, struct mytype, my_node)->num);*/
				
				/*printf("\n");*/
/*}*/

/* Same as find_vma, but also return a pointer to the previous VMA in *pprev. */
/*struct vm_area_struct *                                                             */
/*find_vma_prev(struct mm_struct *mm, unsigned long addr,                             */
					/*struct vm_area_struct **pprev)                                                                                                                                          */
/*{                                                                                   */
	/*struct vm_area_struct *vma = NULL, *prev = NULL;                                */
	/*struct rb_node * rb_node;                                                       */
	/*if (!mm)                                                                        */
		/*goto out;                                                                   */

	/*[> Guard against addr being lower than the first VMA <]                         */
	/*vma = mm->mmap;                                                                 */

	/*[> Go through the RB tree quickly. <]                                           */
	/*rb_node = mm->mm_rb.rb_node;                                                    */

	/*while (rb_node) {                                                               */
		/*struct vm_area_struct *vma_tmp;                                             */
		/*vma_tmp = rb_entry(rb_node, struct vm_area_struct, vm_rb);                  */

		/*if (addr < vma_tmp->vm_end) {                                               */
			/*rb_node = rb_node->rb_left;                                             */
		/*} else {                                                                    */
			/*prev = vma_tmp;                                                         */
			/*if (!prev->vm_next || (addr < prev->vm_next->vm_end))                   */
				/*break;                                                              */
			/*rb_node = rb_node->rb_right;                                            */
		/*}                                                                           */
	/*}                                                                               */

/*out:                                                                                */
	/**pprev = prev;                                                                  */
	/*return prev ? prev->vm_next : vma;                                              */
/*}*/ 

int main(int argc, char *argv[])
{
	return 0;
		/*struct rb_root mytree = RB_ROOT;*/
		/*int i, ret, num;*/
		/*struct mytype *tmp;*/
				 
		/*if (argc < 2) {*/
			/*fprintf(stderr, "Usage: %s num\n", argv[0]);*/
			/*exit(-1);*/
		/*}*/

		/*num = atoi(argv[1]);*/

		/*printf("Please enter %d integers:\n", num);*/
		/*for (i = 0; i < num; i++) {*/
			/*tmp = malloc(sizeof(struct mytype));*/
			/*if (!tmp)*/
				/*perror("Allocate dynamic memory");*/

			/*scanf("%d", &tmp->num);*/

			/*ret = my_insert(&mytree, tmp);*/
			/*if (ret < 0) {*/
				/*fprintf(stderr, "The %d already exists.\n", tmp->num);*/
				/*free(tmp);*/
			/*}*/
		/*}*/

		/*printf("\nthe first test\n");*/
		/*print_rbtree(&mytree);*/

		/*my_delete(&mytree, 21);*/

		/*printf("\nthe second test\n");*/
		/*print_rbtree(&mytree);*/

		/*return 0;*/

}
