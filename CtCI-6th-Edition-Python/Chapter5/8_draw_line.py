# 矩阵M中的每一个元素为一个数字，该数字对应8个bit二进制数

def draw_line(screen, width, x1, x2, y):
    """
    screen:矩阵
    width:矩阵每行的bit个数
         :如果矩阵 1行有8个元素，则每行的bit数为8*矩阵每行的元素个数
    y: 在矩阵的哪一行划线，第一行y为1
    x1: 划线的横坐标起点，哪个bit
    x2: 划线的横坐标终点，哪个bit
    """
    byte_width = width // 8
    height = len(screen) // byte_width
    if x1 < x2:
        x_start, x_end = x1, x2
    else:
        x_start, x_end = x2, x1
    if x_start < 0 or x_end > width or y > height:
        return None
    y -= 1
    byte = y * byte_width + x_start // 8
    byte_end = y * byte_width + x_end // 8
    screen[byte] = (1 << (x_start % 8)) - 1
    byte += 1
    while byte < byte_end:
        screen[byte] = 255
        byte += 1
    screen[byte] = 255 ^ ((1 << (x_end % 8)) - 1)


import unittest

class Test(unittest.TestCase):
    def test_draw_line(self):
        screen = [0, 0, 0, 0, 0, 0, 0, 0,
                  0, 0, 0, 0, 0, 0, 0, 0,
                  0, 0, 0, 0, 0, 0, 0, 0]
        draw_line(screen, 64, 20, 42, 2)
        self.assertEqual(screen, [0]*8 + [0, 0, 15, 255, 255, 252, 0, 0] + [0]*8)

if __name__ == "__main__":
    unittest.main()

