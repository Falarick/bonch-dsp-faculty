#!/usr/bin/python3
import numpy as np
import matplotlib.pyplot as plt

from utils import *


signal   = read_signal("../data/signal.bin")
filtered = read_signal("../data/filtered.bin")
flt      = read_signal("../data/filter.bin")

Fs = 200E3
taps    = flt.shape[0]
samples = filtered.shape[0] - taps + 1
t = np.linspace(0, samples / Fs, samples)

plt.figure(figsize=(20, 10))

plt.suptitle("Convolution result: Time/Frequency domain")

plt.subplot(211)
plt.plot(t[:400], signal[taps - 1 : 400 + taps - 1], label='Original')
plt.plot(t[:400], filtered[:400], c='r', label='Filtered')
plt.legend()
plt.grid(True)

plt.subplot(212)
plt.magnitude_spectrum(signal, Fs=Fs, scale='dB', label='Original')
plt.magnitude_spectrum(filtered, Fs=Fs, scale='dB', c='r', label='Filtered')
plt.legend()
plt.grid(True)

plt.show()

