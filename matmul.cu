// 实现一个矩阵乘法

__global__ void matmul(float* A, float* B, float*C, int M, int N, int K) {
    // 计算行列号
    int row = blockDim.x * blockIdx.x + threadIdx.x;
    int col = blockDim.y * blockIdx.y + threadIdx.y;

    // 边界条件,避免越界
    if (row >= M || col >= N) {
        return;
    }

    // A的row行k列 B的k行col列
    float acc = 0;
    for (int k = 0; k < K; ++k) {
        acc = A[row * K + k] * B[k * N + col];
    }

    // C的row行col列
    C[row * N + col] = out;
}

// 向上取整的除法
#define CEIL_DIV(a, b) ((a + b - 1) / b)

int main() {
    // 初始化矩阵A，B，C

    dim3 blockDim(16, 16);
    dim3 gridDim(CEIL_DIV(blockDim.x), CEIL_DIV(blockDim.y));
    <<<gridDim, blockDim>>>matmul(A, B, C, M, N, K);

    return 0;
}

