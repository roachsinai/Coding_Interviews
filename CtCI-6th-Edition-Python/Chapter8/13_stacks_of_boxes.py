# 叠箱子，一个箱子只有长宽高都小于另一个箱子才可以放到另一个箱子上面。
# 求一组箱子能够叠出的最大高度

def stack_boxes(boxes):
    sorted_boxes = sorted(boxes, key=lambda box: box.height, reverse=True)
    return stack_more_boxes(sorted_boxes, None, 0)

def stack_more_boxes(boxes, base, index):
    """
    boxes: 按照高度排序之后的箱子
    base: 当前叠好的箱子最上面的箱子
    index: 考虑第index箱子叠不叠

    待改进的地方：本函数可以增加一个缓存heights, height[i]表示以第i个箱子为底的最大高度
                因为本函数调用的子函数两次，有重复调用
    """
    if index >= len(boxes):
        return 0
    without_box_height = stack_more_boxes(boxes, base, index + 1)
    box = boxes[index]
    if (not base) or box.fits_on(base):
        with_box_height = box.height + stack_more_boxes(boxes, box, index + 1)
        if with_box_height > without_box_height:
            return with_box_height
    return without_box_height


def stack_boxes_dp(boxes):
    """使用动态归化的思想：同样将箱子按照高度降序排列，计heights[i]为到第i个箱子为止叠到的最大高度
    第i个箱子前面的所有宽高比第i个箱子大的箱子集合为J，heights[i] = i.height + max(heights[j]) for j in J
    而能够叠到的最大高度hmax = hmax(highets[i], hmax)

    感觉这个方法没有上面加缓存的快
    """


class Box(object):

    def __init__(self, height, width, depth):
        self.height, self.width, self.depth = height, width, depth

    def fits_on(self, base):
        return base.width > self.width and \
               base.depth > self.depth

import unittest

class Test(unittest.TestCase):
    def test_stack_boxes(self):
        boxes = [Box(100, 100, 100)]
        self.assertEqual(stack_boxes(boxes), 100)
        boxes.append(Box(25, 25, 25))
        self.assertEqual(stack_boxes(boxes), 125)
        boxes.append(Box(20, 5, 30))
        boxes.append(Box(17, 4, 28))
        self.assertEqual(stack_boxes(boxes), 137)

if __name__ == "__main__":
    unittest.main()
