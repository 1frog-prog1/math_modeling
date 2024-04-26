import imageio as iio
from pathlib import Path

images = list()
for file in Path("C:/Users/gosum/Desktop/Шизашизы/assets6v2").iterdir():
    if not file.is_file():
        continue

    images.append(iio.imread(file))

iio.mimsave('C:/Users/gosum/Desktop/Шизашизы/movie.gif', images, duration=0.04)