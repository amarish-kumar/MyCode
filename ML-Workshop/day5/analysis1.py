import pandas as pd
from pylab import *
#import matplotlib.pyplot as plt
pd.set_option('max_columns', 50)

# pass in column names for each CSV
u_cols = ['user_id', 'age', 'sex', 'occupation', 'zip_code']
users = pd.read_csv('\ml-100k\u.user', sep='|', names=u_cols)

r_cols = ['user_id', 'movie_id', 'rating', 'unix_timestamp']
ratings = pd.read_csv('\ml-100k\u.data', sep='\t', names=r_cols)

# the movies file contains columns indicating the movie's genres
# let's only load the first five columns of the file with usecols
m_cols = ['movie_id', 'title', 'release_date', 'video_release_date', 'imdb_url']
movies = pd.read_csv('\ml-100k\u.item', sep='|', names=m_cols, usecols=range(5))

# create one merged DataFrame
movie_ratings = pd.merge(movies, ratings)
lens = pd.merge(movie_ratings, users)

print lens

most_rated = lens.groupby('title').size().order(ascending=False)[:10]
print most_rated.plot()
show()
