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
