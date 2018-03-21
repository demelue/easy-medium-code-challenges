def dice_roll_util(dice, vec):
    if dice == 0:
        print(vec)
    else:
        i = 1
        while i <= 6:
            vec.append(i)
            dice_roll_util(dice - 1, vec)
            vec.pop(-1)
            i += 1

def dice_roll(dice):
    vec = []
    dice_roll_util(dice, vec)

if __name__=='__main__':
    dice_roll(3)
