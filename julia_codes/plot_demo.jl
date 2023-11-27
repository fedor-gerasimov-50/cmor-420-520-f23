using Plots

gr()
plotly()

x = LinRange(0, 10, 100)
y = sin.(x)
anim = @animate for i in eachindex(y)
    plot(x, y)
    plot!([x[i]], [y[i]], legend = false, 
                          marker = :dot, 
                          markersize = 10)
end

gif(anim, "sine.gif")



θ = LinRange(-2 * pi, 2 * pi, 500)
ϕ = LinRange(-2 * pi, 2 * pi, 500)
x = @. sin(θ) * cos(ϕ)
y = @. sin(θ) * sin(ϕ)
z = @. cos(θ)

camera_angles = LinRange(0, 70, 500)

@gif for i in eachindex(x)
    plot(x, y, z)
    plot!([x[i]], [y[i]], [z[i]], 
          legend=false, marker=:dot, markersize=10, 
          camera = (camera_angles[i], 10), 
          grid = true)
end every 5

