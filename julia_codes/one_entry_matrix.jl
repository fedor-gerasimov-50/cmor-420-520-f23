
struct OneEntryMatrix{T} <: AbstractMatrix{T}
    m::Int
    n::Int
    value::T
    row::Int
    column::Int
end

import Base: size, getindex
size(A::OneEntryMatrix) = (A.m, A.n)
function getindex(A::OneEntryMatrix, i, j)
    if i == A.row && j == A.column
        return A.value
    else
        return zero(A.value)
    end
end

import LinearAlgebra: mul!

function mul!(out, A::OneEntryMatrix, x::AbstractVector)
    println("Running my custom multiplication")
    out .= 0
    out[A.row] = A.value * x[A.column]
    return out
end







struct OneEntryMatrix{T} <: AbstractMatrix{T}
    row::Int64
    column::Int64
    value::T
    num_rows::Int64
    num_columns::Int64
    function OneEntryMatrix(m, n, row_and_column, value)
        i, j = row_and_column
        return new{typeof(value)}(i, j, value, m, n)
    end
end

import Base: size, getindex
size(A::OneEntryMatrix) = A.num_rows, A.num_columns
getindex(A::OneEntryMatrix, i, j) = (i==A.row && j==A.column) * A.value

import LinearAlgebra: mul!
function mul!(out, A::OneEntryMatrix, x::AbstractVector)
    fill!(out, zero(eltype(x)))
    out[A.row] = A.value * x[A.column]
    return out
end

