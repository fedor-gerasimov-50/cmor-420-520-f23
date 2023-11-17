module CanonicalBasisVectors

export CanonicalBasisVector, inner

# load the "dot" function, which we will use
using LinearAlgebra: dot

# This will define a custom vector type: a canonical basis vector
#       e_i = [0, 0, ..., 1, ..., 0]
#                    (ith entry)
# using the "AbstractArray" interface in Julia. 
struct CanonicalBasisVector <: AbstractVector{Bool}
    index::Int
    length::Int
end

import Base: size, getindex
size(x::CanonicalBasisVector) = (x.length, )
getindex(x::CanonicalBasisVector, i) = x.index == i

include("inner.jl")

end