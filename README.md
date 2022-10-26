My first graphical project with a mission of reproduce a isometric projection of a cartesian map file.

Example of file:

![image](https://user-images.githubusercontent.com/102628898/197907606-18494eb3-e258-44c2-9e4b-597a6ad1cfe0.png)

The result is:

![image](https://user-images.githubusercontent.com/102628898/197907927-94b451f3-b96a-4250-bd48-92958f20fb35.png)

------------------------------------------------------------------

How to test this program

![image](https://user-images.githubusercontent.com/102628898/197909499-09d91e19-0530-4174-8e8a-2cfb69cdf8d8.png)

1 - Clone the repository with a command:
' git clone git@github.com:dougrasf/fdf.git fdf '

2 - Compile with Makefile: 
' make '

3 - Execute the program:
' ./fdf test_maps/MAPNAME.fdf '

------------------------------------------------------------------

List of controls: 

W A S D -> Movements

. and , -> Zoom adjust

K and L -> Z point adjust

I -> Isometric projection

P -> Parallel projection

C -> Change colors

X -> Reset original colors

Q or ESC -> Exit

------------------------------------------------------------------

![image](https://user-images.githubusercontent.com/102628898/197909707-5d15e9d5-a80d-49ad-a6d5-f4966cd5fd8c.png)

Enjoy!
