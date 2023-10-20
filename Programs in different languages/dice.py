'''

DICE

A six-sided dice is a small cube with a different number of pips on each face(side), 
ranging from 1 to 6. On any two opposite sides of the cube, the number of pips adds up to 7;
that is, there are three pairs of opposite sides: 1 and 6, 2 and 5, 3 and 4.

There are N dice lying on a table, each showing the pips on its top face. In one move, 
you can take one dice and rotate it to an adjacent face. For example, you can rotate a dice that 
show 1 so that it shows 2, 3, 4 or 5. however, it can't show 6 in single move, because 
the face with one pip and six pips visible are on opposite side rather than adjacent.

You want to show the same number of pips on the top faces of all N dice. Given that each of 
the dice can be moved multiple times, count the minimum number of moves needed to get equal faces.

Input Specification:
The array A with consisting of N integers describing the number of pips (from 1 to 6)

Example:
A: [1, 1, 6]
Output: 2
Explanation:
The only optimal answer is to rotate the last dice so that it shows one pip. It is necessary 
to use two rotations to achive this

A: [1, 6, 2, 3]
Output: 3
Explanation:
For instance, you can make all dice show 2: just rotate each diece which is not showing 2 
(and notice that for each dice you can do this in one move)

'''
n = input('dices N: ')
n = int(n)
dices = []
for i in range(n):
    pip = input('dice pips ' + str(i) + ':')
    pip = int(pip)

    # check pips input
    if pip < 1 or pip > 6:
        raise Exception('dice pips only 1 to 6!')

    dices.append(pip)

def get_rotation(current_pip, target_pip):
    if current_pip == 1:
        return 2 if target_pip == 6 else 1
    elif current_pip == 2:
        return 2 if target_pip == 5 else 1
    elif current_pip == 3:
        return 2 if target_pip == 4 else 1
    elif current_pip == 4:
        return 2 if target_pip == 3 else 1
    elif current_pip == 5:
        return 2 if target_pip == 2 else 1
    elif current_pip == 6:
        return 2 if target_pip == 1 else 1
    else:
        return 0 # error

opt_rotation = 0
for i, target_pip in enumerate(dices):
    print('target pip: ' + str(target_pip))

    rotation = 0
    for j, current_pip in enumerate(dices):
        if i == j:
            continue
        
        if target_pip == current_pip:
            continue

        rotation += get_rotation(current_pip, target_pip)
    
    if opt_rotation == 0:
        opt_rotation = rotation
    else:
        if rotation < opt_rotation:
            opt_rotation = rotation
    
    print('rotation needed: ' + str(rotation))

print('')
print('optimal rotation: ' + str(opt_rotation))
