import numpy as np

def dump_signal(filename, signal, t):
    payload = int(t).to_bytes(4, 'little') + \
              int(len(signal.shape)).to_bytes(4, 'little')
    for axis in signal.shape:
        payload += int(axis).to_bytes(8, 'little')
    payload += signal.tobytes()
        
    with open(filename, "wb") as f:
        f.write(payload)
        
        
def read_signal(filename):
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
    signal = np.frombuffer(payload, np.float32, length, offset)
    return signal.reshape(shape)