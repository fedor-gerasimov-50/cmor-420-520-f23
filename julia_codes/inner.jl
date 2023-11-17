# inner product u' * A * v
inner(u, A, v) = dot(u, A * v) # a general fallback

# some specialized behavior
inner(u::CanonicalBasisVector, A, v) = dot(A[u.index, :], v)
inner(u, A, v::CanonicalBasisVector) = dot(u, A[:, v.index])
inner(u::CanonicalBasisVector, A, 
      v::CanonicalBasisVector) = A[u.index, v.index]
