#include <cstddef>
#include <cstdlib>
#include <cstring>

typedef struct
{
    float *data;
    size_t nrows;
    size_t ncols;
} matrix;

enum matrix_err_code
{
    MATRIX_SUCCESS,
    MATRIX_ERR_MEMORY_INSUFFICIENT,
    MATRIX_ERR_MISMATCHED_MATRIX_SIZE,
};

int matrix_alloc(matrix *ptr, size_t nrows, size_t ncols)
{
    size_t size = nrows * ncols * sizeof(float);
    float *data = (float *)malloc(size);
    if (data == NULL)
    {
        return MATRIX_ERR_MEMORY_INSUFFICIENT;
    }
    ptr->data = data;
    ptr->nrows = nrows;
    ptr->ncols = ncols;
}

void matrix_dealloc(matrix *ptr)
{
    if (ptr->data == NULL)
    {
        return;
    }
    free(ptr->data);
    ptr->data = NULL;
    ptr->nrows = 0;
    ptr->ncols = 0;
}

int matrix_multiply(matrix *result, const matrix *lhs, const matrix *rhs)
{
    int errcode;
    if (lhs->ncols != rhs->nrows)
    {
        return MATRIX_ERR_MISMATCHED_MATRIX_SIZE;
    }
    errcode = matrix_alloc(result, lhs->nrows, rhs->ncols);
    if (errcode != MATRIX_SUCCESS)
    {
        return errcode;
    }
    // ...
    return MATRIX_SUCCESS;
}

int main()
{
    matrix c;
    memset(&c, 0, sizeof(matrix));
    matrix a, b;
    int errcode = matrix_alloc(&a, 3, 3);
    if (errcode != MATRIX_SUCCESS)
    {
        goto error_exit;
    }
    errcode = matrix_alloc(&b, 3, 3);
    if (errcode != MATRIX_SUCCESS)
    {
        goto error_exit;
    }

    errcode = matrix_multiply(&c, &a, &b);
    if (errcode != MATRIX_SUCCESS)
    {
        goto error_exit;
    }
error_exit:
    matrix_dealloc(&c);
    return errcode;
}