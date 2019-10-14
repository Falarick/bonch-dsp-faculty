#!/usr/bin/python3
import numpy as np
import matplotlib.pyplot as plt

from utils import *


signal   = to_complex(read_signal("../data/signal_16bit.bin", np.int16))
filtered = to_complex(read_signal("../data/filtered_16bit.bin", np.int16))

Fs = 200E3

plt.figure(figsize=(20, 10))
plt.suptitle("Complex convolution result:")
plt.magnitude_spectrum(signal, Fs=Fs, scale='dB', label='Original')
plt.magnitude_spectrum(filtered, Fs=Fs, scale='dB', c='r', label='Filtered')
plt.legend()
plt.grid(True)

plt.show()

