using StaticArrays
using BenchmarkTools

A = randn(100, 100)

function lots_of_dots(A)
    val = 0
    for i in axes(A, 1) # rows
        for j in axes(A, 2) # columns
            if i < size(A, 1) & j < size(A, 2)
                a = A[i:i+1, j]
                b = A[i, j:j+1]
                val += dot(a, b)
            end
        end
    end
    return val
end

function lots_of_dots_explicit(A)
    val = 0
    for i in axes(A, 1) # rows
        for j in axes(A, 2) # columns
            if i < size(A, 1) & j < size(A, 2)
                val += A[i,j] * A[i,j] + A[i+1,j] * A[i,j+1]
            end
        end
    end
    return val
end

function lots_of_dots_loop(A)
    val = 0
    for i in axes(A, 1)
        for j in axes(A, 2)
            if i < size(A, 1) & j < size(A, 2)
                for ii in 0:1
                    a = A[i + ii, j]
                    b = A[i, j + ii]
                    val += a * b
                end
            end
        end
    end
    return val
end

function lots_of_dots_prealloc(A)
    val = 0
    a, b = zeros(2), zeros(2)
    for i in axes(A, 1)
        for j in axes(A, 2)
            if i < size(A, 1) & j < size(A, 2)
                @. a = A[i:i+1, j]
                @. b = A[i, j:j+1]
                val += dot(a, b)
            end
        end
    end
    return val
end

function lots_of_dots_views(A)
    val = 0
    for i in axes(A, 1)
        for j in axes(A, 2)
            if i < size(A, 1) & j < size(A, 2)
                a = @view A[i:i+1, j]
                b = @view A[i, j:j+1]
                val += dot(a, b)
            end
        end
    end
    return val
end

function lots_of_dots_static_arrays(A)
    val = 0
    for i in axes(A, 1)
        for j in axes(A, 2)
            if i < size(A, 1) & j < size(A, 2)
                a = SVector(A[i, j], A[i+1, j])
                b = SVector(A[i, j], A[i, j+1])
                val += dot(a, b)
            end
        end
    end
    return val
end