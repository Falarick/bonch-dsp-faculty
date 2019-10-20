import numpy as np

"""
DSP_UINT8   = 0, ///< int8_t
DSP_INT16   = 1, ///< int16_t
DSP_INT32   = 2, ///< int32_t
DSP_FLOAT32 = 3, ///< float
DSP_FLOAT64 = 4  ///< double
"""
def type_map(dtype):
    if dtype == np.uint8:
        return 0
    if dtype == np.int16:
        return 1
    if dtype == np.int32:
        return 2
    if dtype == np.float32:
        return 3
    if dtype == np.float64:
        return 4
    if dtype == np.int8:
        return 5

def to_complex(s):
    return s[:, 0] + 1j * s[:, 1]

def dump_signal(filename, signal, dtype):
    payload = int(type_map(dtype)).to_bytes(4, 'little') + \
              int(len(signal.shape)).to_bytes(4, 'little')
    for axis in signal.shape:
        payload += int(axis).to_bytes(8, 'little')
    payload += dtype(signal).tobytes()
        
    with open(filename, "wb") as f:
        f.write(payload)
        
        
def read_signal(filename, dtype=np.float32):
    with open(filename, "rb") as f:
        payload = f.read()
        
    offset = 4
    dims = np.frombuffer(payload, np.int32, 1, offset)[0]
    offset += 4
    shape = []
    length = 1
    for i in range(dims):
        shape.append(np.frombuffer(payload, np.int64, 1, offset)[0])
        length *= shape[-1] 
        offset += 8
    shape = tuple(shape)
    signal = np.frombuffer(payload, dtype, length, offset)
    return signal.reshape(shape)