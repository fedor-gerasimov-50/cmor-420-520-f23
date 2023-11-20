function mysum(x)
    val = 0.0
    for i in eachindex(x)
        if (i-1) % 2 == 0 
            val += x[i] 
        else
            val -= x[i] 
        end
    end
    return val
end

function mysum_global()
    val = 0.0
    for i in eachindex(x)
        if (i-1) % 2 == 0 
            val += x[i] 
        else
            val -= x[i] 
        end
    end
    return val
end

abstract type AbstractFoo end

struct FooTypeExplicit <: AbstractFoo
    x::Vector{Float64}
end

struct FooTypeInferred{T} <: AbstractFoo
    x::T
end

struct FooTypeNotDefined <: AbstractFoo
    x
end

struct FooTypeAbstract <: AbstractFoo
    x::Vector{AbstractFloat}
end


function mysum(x::AbstractFoo)
    val = 0.0
    for i in eachindex(x.x)
        if (i-1) % 2 == 0 
            val += x.x[i] 
        else
            val -= x.x[i] 
        end
    end
    return val
end