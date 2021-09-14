/**
 * 该程序用于声明数据类型的结构体和函数体
 *
 * mnn_vector:       int, double*
 * mnn_matrix:       int, int, double**
 * mnn_network:      int, mnn_vector, int
 * mnn_network_options:        char*, char*, char*, char*, int
 * mnn_training_parameters:    int, int, double
 * mnn_network_configuration:  mnn_network*, mnn_training_parameters*
 * mnn_backpagation_data:      mnn_vector*, mnn_matrix*
 *
 * and some allocation of those struct function
 */

#include "mnn_data_structure.h"

/*
给mnn_vector分配内存
typedef struct mnn_vector_//mnt向量
{
    size_t length;//长度
    double* values;//双精度浮点指针
} mnn_vector;
*/
mnn_vector
allocate_vector (size_t length)
{
    /**/
    __assert ("'allocate_vector' function ('mnn_data_structure.c'),"\
                " length <= 0", length > 0);

    int k;
    mnn_vector v;

    v.length = length;
    v.values = (double *) malloc (v.length * sizeof (double));
    if (!v.values)
        __exit ("'allocate_vector' function ('mnn_data_structure.c'),"\
                " impossible to allocate vector");

    /* Init values */
    for (k = 0; k < v.length; k++)
        v.values[k] = 0.0;

    return v;
}

/*
分配一个mnn_matrix内存
typedef struct mnn_matrix_//mnn矩阵
{
    size_t rows;//行
    size_t cols;//列
    double** values;//双精度二维浮点指针
} mnn_matrix;
*/
mnn_matrix
allocate_matrix (size_t rows, size_t cols)
{
    __assert ("'allocate_matrix' function ('mnn_data_structure.c'),"\
                " rows <= 0", rows > 0);
    __assert ("'allocate_matrix' function ('mnn_data_structure.c'),"\
                " cols <= 0", cols > 0);

    mnn_matrix m;
    int k, j;

    m.rows   = rows;
    m.cols   = cols;
    m.values = (double **) malloc (m.rows * sizeof (double *));
    if (!m.values)
        __exit ("'allocate_matrix' function ('mnn_data_structure.c'),"\
                " impossible to allocate m.values");

    for (k = 0; k < m.rows; k++)
        if (!(m.values[k] = ((double *) malloc (m.cols * sizeof (double)))))
            __exit ("'allocate_matrix' function ('mnn_data_structure.c'),"\
                    " impossible to allocate m.values[k]");

    /* Init values */
    for (k = 0; k < m.rows; k++)
        for (j = 0; j < m.cols; j++)
            m.values[k][j] = 0.0;

    return m;
}
/**
 *矩阵点乘：[k][j] = [k][i]*[i][j]
 */
mnn_matrix
matrix_dot_matrix (mnn_matrix m_1, mnn_matrix m_2)
{
    __assert ("'matrix_dot_matrix' function ('mnn_data_structure.c'),"\
                " m_1.rows <= 0", m_1.rows > 0);
    __assert ("'matrix_dot_matrix' function ('mnn_data_structure.c'),"\
                " m_1.cols <= 0", m_1.cols > 0);
    __assert ("'matrix_dot_matrix' function ('mnn_data_structure.c'),"\
                " m_2.rows <= 0", m_2.rows > 0);
    __assert ("'matrix_dot_matrix' function ('mnn_data_structure.c'),"\
                " m_2.cols <= 0", m_2.cols > 0);
    __assert ("'matrix_dot_matrix' function ('mnn_data_structure.c'),"\
                " m_1.cols != m_2.rows", m_1.cols == m_2.rows);

    int k, j, i;
    mnn_matrix m_result;

    m_result = allocate_matrix (m_1.rows, m_2.cols);
    for (k = 0; k < m_1.rows; k++)
        for (j = 0; j < m_2.cols; j++)
            for (i = 0; i < m_1.cols; i++)
                m_result.values[k][j] += m_1.values[k][i] * m_2.values[i][j];

    return m_result;
}

/**
 *矩阵转置
 */
mnn_matrix
matrix_transpose (mnn_matrix m)
{
    __assert ("'matrix_transpose' function ('mnn_data_structure.c'),"\
                " m.rows <= 0", m.rows > 0);
    __assert ("'matrix_transpose' function ('mnn_data_structure.c'),"\
                " m.cols <= 0", m.cols > 0);

    int k, j;
    mnn_matrix m_T;

    m_T = allocate_matrix (m.cols, m.rows);
    for (k = 0; k < m.rows; k++)
        for (j = 0; j < m.cols; j++)
            m_T.values[j][k] = m.values[k][j];

    return m_T;
}

/*
矩阵的值乘以sigmoid函数
*/
mnn_matrix
matrix_sigmoid (mnn_matrix m)
{
    __assert ("'matrix_sigmoid' function ('mnn_data_structure.c'),"\
                " m.rows <= 0", m.rows > 0);
    __assert ("'matrix_sigmoid' function ('mnn_data_structure.c'),"\
                " m.cols <= 0", m.cols > 0);

    int k, j;
    mnn_matrix m_s;

    m_s = allocate_matrix (m.rows, m.cols);
    for (k = 0; k < m.rows; k++)
        for (j = 0; j < m.cols; j++)
            m_s.values[k][j] = sigmoid_to_number (m.values[k][j]);

    return m_s;
}

/*
矩阵的值乘以两次求sigmoid函数的导数
例如：  y = x^2
 则：   y = (x^2)^2
*/
mnn_matrix
matrix_sigmoid_prime (mnn_matrix m)
{
    __assert ("'matrix_sigmoid' function ('mnn_data_structure.c'),"\
                " m.rows <= 0", m.rows > 0);
    __assert ("'matrix_sigmoid' function ('mnn_data_structure.c'),"\
                " m.cols <= 0", m.cols > 0);

    int k, j;
    mnn_matrix m_s_p;

    m_s_p = allocate_matrix (m.rows, m.cols);
    for (k = 0; k < m.rows; k++)
        for (j = 0; j < m.cols; j++)
            m_s_p.values[k][j] = sigmoid_prime_to_number (m.values[k][j]);

    return m_s_p;
}

/*显示一个向量【】*/
void
print_vector (mnn_vector v)
{
    int k;

    printf ("[");
    for (k = 0; k < v.length; k++)
        printf ((k != v.length - 1) ? "%f, " : "%f", v.values[k]);
    printf ("]");
}
/*打印一个矩阵【】【】*/
void
print_matrix (mnn_matrix m)
{
    int k, j;

    for (k = 0; k < m.rows; k++) {
        printf ("\n");
        for (j = 0; j < m.cols; j++)
            printf ("%f  ", m.values[k][j]);
    }
}

/*释放内存*/
void
free_vector (mnn_vector v)
{
    free (v.values);
}

/*释放内存*/
void
free_matrix (mnn_matrix m)
{
    int k;

    for (k = 0; k < m.rows; k++)
        free (m.values[k]);

    free (m.values);
}
