:for
D_data.exe > d.in
D_std.exe < d.in > d.std
D.exe < d.in > d.out

fc d.out d.std

goto for
