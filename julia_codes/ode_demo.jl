using OrdinaryDiffEq

# dy₁/dt = 1 + y₁² * y₂ - (B+1) * y1
# dy₂/dt = B * y1 - y1^2 * y2

# rhs for the "Brusselator" system
function brusselator!(du, u, p, t)
    (; B) = p
    y1, y2 = u[1], u[2]
    du[1] = 1 + y1^2 * y2 - (B+1) * y1
    du[2] = B * y1 - y1^2 * y2
end

function lorenz!(du,u,p,t)
    σ, ρ, β = p
    du[1] = σ*(u[2]-u[1])
    du[2] = u[1]*(ρ-u[3]) - u[2]
    du[3] = u[1]*u[2] - β*u[3]
end

prob = ODEProblem(brusselator!, [0; 0], (0, 50.0), (; B=3.0))
sol = solve(prob, SSPRK43())

plot(sol)
