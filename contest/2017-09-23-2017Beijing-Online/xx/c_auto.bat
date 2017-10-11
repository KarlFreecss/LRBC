:for
c_data.exe > c.in
c_force.exe < c.in > c_force.out
c_std.exe < c.in > c_std.out

fc c_std.out c_force.out
if errorlevel == 1 pause

goto for
