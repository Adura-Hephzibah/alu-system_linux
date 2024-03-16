#include <Python.h>
#include <stdio.h>

/**
 * print_python_list - prints some basic info for Python lists
 * @p: pointer to Python List Object
 **/
void print_python_list(PyObject *p)
{
	int size = (((PyVarObject *)(p))->ob_size);
	int alloc = (((PyListObject *)(p))->allocated);

	printf("[*] Python list info\n");
	printf("[*] Size of the Python List = %d\n", size);
	printf("[*] Allocated = %d\n", alloc);
	int i;

	for (i = 0; i < size; i++)
		printf("Element %d: %s\n", i, PyList_GetItem(p, i)->ob_type->tp_name);
}
