# 二维数组中每个元素代表一种颜色（数字代替），给某个位置指定一种新的颜色之后
# 在该位置的上下左右四个方位，颜色和原来颜色相同的颜色也进行更新
# 指定的颜色必须和原来的颜色不同，否则paint_fill操作就是死循化（除非该位置周围没有
# 颜色相同的元素）

def paint_fill(image, x, y, color):
    if x < 0 or y < 0 or len(image) <= y or len(image[y]) <= x:
        return
    old_color = image[y][x]
    if old_color == color:
        return
    paint_fill_color(image, x, y, color, old_color)

def paint_fill_color(image, x, y, new_color, old_color):
    if image[y][x] != old_color:
        return
    image[y][x] = new_color
    if y > 0:
        paint_fill_color(image, x, y - 1, new_color, old_color)
    if y < len(image) - 1:
        paint_fill_color(image, x, y + 1, new_color, old_color)
    if x > 0:
        paint_fill_color(image, x - 1, y, new_color, old_color)
    if x < len(image[y]) - 1:
        paint_fill_color(image, x + 1, y, new_color, old_color)


import unittest

class Test(unittest.TestCase):
    def test_paint_fill(self):
        image1 = [[10, 10, 10, 10, 10, 10, 10, 40],
                  [30, 20, 20, 10, 10, 40, 40, 40],
                  [10, 10, 20, 20, 10, 10, 10, 10],
                  [10, 10, 30, 20, 20, 20, 20, 10],
                  [40, 40, 10, 10, 10, 10, 10, 10]]
        image2 = [[30, 30, 30, 30, 30, 30, 30, 40],
                  [30, 20, 20, 30, 30, 40, 40, 40],
                  [10, 10, 20, 20, 30, 30, 30, 30],
                  [10, 10, 30, 20, 20, 20, 20, 30],
                  [40, 40, 30, 30, 30, 30, 30, 30]]
        image3 = [[30, 30, 30, 30, 30, 30, 30, 40],
                  [30, 20, 20, 30, 30, 40, 40, 40],
                  [30, 30, 20, 20, 30, 30, 30, 30],
                  [30, 30, 30, 20, 20, 20, 20, 30],
                  [40, 40, 30, 30, 30, 30, 30, 30]]
        paint_fill(image1, 3, 1, 30)
        self.assertEqual(image1, image2)
        paint_fill(image1, 3, 1, 10)
        paint_fill(image1, 3, 1, 30)
        self.assertEqual(image1, image3)

if __name__ == "__main__":
    unittest.main()
