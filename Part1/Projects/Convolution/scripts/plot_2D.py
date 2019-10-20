#!/usr/bin/python3
import numpy as np
import matplotlib.pyplot as plt

from utils import *


image  = read_signal("../data/im_female.bin", np.uint8)
fimage = read_signal("../data/fim_female.bin", np.uint8)

plt.figure(figsize=(20, 10))
plt.suptitle("2D Convolution [Gaussian Filter]")
plt.subplot(121)
plt.imshow(image, cmap='gray', vmin=0, vmax=255)
plt.subplot(122)
plt.imshow(fimage, cmap='gray', vmin=0, vmax=255)
plt.show()

