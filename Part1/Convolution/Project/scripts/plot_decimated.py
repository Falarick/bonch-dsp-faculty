#!/usr/bin/python3
import numpy as np
import matplotlib.pyplot as plt

from utils import *


signal    = read_signal("../data/signal.bin")
decimated = read_signal("../data/decimated.bin")
flt       = read_signal("../data/filter.bin")

taps = flt.shape[0]

Fs = 200E3
samples = signal.shape[0] - taps + 1
t = np.linspace(0, samples / Fs, samples)

Fd = 200E3 / 4
td = np.linspace(0, decimated.shape[0] / Fd, decimated.shape[0])

plt.figure(figsize=(20, 10))
plt.suptitle("Convolution/Decimation result: Time/Frequency domain")

plt.subplot(311)
plt.plot(t[:400], signal[taps - 1 : 400 + taps - 1], label='Original')
plt.plot(td[:100], decimated[:100], c='r', label='Filtered/Decimated')
plt.legend()
plt.grid(True)

plt.subplot(312)
plt.magnitude_spectrum(signal, Fs=Fs, scale='dB', label='Original')
plt.legend()
plt.grid(True)

plt.subplot(313)
plt.magnitude_spectrum(decimated, Fs=Fd, scale='dB', c='r', label='Filtered/Decimated')
plt.legend()
plt.grid(True)

plt.show()

