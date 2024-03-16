#include <Python.h>
#include <float.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * print_python_bytes - prints info about python bytes object
 * @p: Python generic object
 */
void print_python_bytes(PyObject *p)
{
	int i;
	int size = (((PyVarObject *)(p))->ob_size);

	printf("[.] bytes object info\n");
	if (!PyBytes_Check(p))
	{
		printf("  [ERROR] Invalid Bytes Object\n");
		return;
	}
	printf("  size: %d\n", size);
	printf("  trying string: %s\n", ((PyBytesObject *)p)->ob_sval);
	if (size > 9)
		size = 10;
	else
		size++;
	printf("  first %d bytes: ", size);
	for (i = 0; i < size; i++)
	{
		printf("%02hhx", (((PyBytesObject *)(p))->ob_sval[i]));
		if (i == size - 1)
			printf("\n");
		else
			printf(" ");
		fflush(stdout);

	}
}

/**
 * print_python_float - prints info about python float object
 * @p: Python generic object
 */
void print_python_float(PyObject *p)
{
	char *str;
	double flt;

	printf("[.] float object info\n");
	if (!PyFloat_Check(p))
	{
		printf("  [ERROR] Invalid Float Object\n");
		return;
	}
	flt = (((PyFloatObject *)(p))->ob_fval);
	str = PyOS_double_to_string(flt, 'g', 16, 0, NULL);
	if (strchr(str, '.'))
		printf("  value: %s\n", str);
	else
		printf("  value: %s.0\n", str);

	fflush(stdout);
}

/**
 * print_python_list - prints some basic info for Python lists
 * @p: pointer to Python List Object
 **/
void print_python_list(PyObject *p)
{
	int size = (((PyVarObject *)(p))->ob_size);
	int alloc = (((PyListObject *)(p))->allocated);

	if (!PyList_Check(p))
	{
		printf("  [ERROR] Invalid List Object\n");
		return;
	}

	printf("[*] Python list info\n");
	printf("[*] Size of the Python List = %d\n", size);
	printf("[*] Allocated = %d\n", alloc);
	int i;

	for (i = 0; i < size; i++)
	{
		PyObject *item = (((PyListObject *)(p))->ob_item[i]);

		printf("Element %d: %s\n", i, item->ob_type->tp_name);
		if (PyBytes_Check(item))
		{
			print_python_bytes(item);
		}
		if (PyFloat_Check(item))
			print_python_float(item);
		fflush(stdout);
	}
}
