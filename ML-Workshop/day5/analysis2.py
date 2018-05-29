__author__ = 'Ashish'
import pandas as pd
import numpy as np
from pylab import *
#import matplotlib.pyplot as plt
pd.set_option('max_columns', 50)

# pass in column names for each CSV
u_cols = ['user_id', 'age', 'sex', 'occupation', 'zip_code']
users = pd.read_csv('Data\ml-100k\u.user', sep='|', names=u_cols)

r_cols = ['user_id', 'movie_id', 'rating', 'unix_timestamp']
ratings = pd.read_csv('Data\ml-100k\u.data', sep='\t', names=r_cols)

# the movies file contains columns indicating the movie's genres
# let's only load the first five columns of the file with usecols
m_cols = ['movie_id', 'title', 'release_date', 'video_release_date', 'imdb_url']
movies = pd.read_csv('Data\ml-100k\u.item', sep='|', names=m_cols, usecols=range(5))

# create one merged DataFrame
movie_ratings = pd.merge(movies, ratings)
lens = pd.merge(movie_ratings, users)


labels = ['0-9', '10-19', '20-29', '30-39', '40-49', '50-59', '60-69', '70-79']
lens['age_group'] = pd.cut(lens.age, range(0, 81, 10), right=False, labels=labels)



#print lens[['age', 'age_group']].drop_duplicates()[:10]

print "===================================================="


#Now we can now compare ratings across age groups.
print lens.groupby('age_group').agg({'rating': [np.size, np.mean]})

print "===================================================="


most_50 = lens.groupby('movie_id').size().order(ascending=False)[:50]

print most_50

lens.set_index('movie_id', inplace=True)

by_age = lens.ix[most_50.index].groupby(['title', 'age_group'])
by_age.rating.mean().head(15)

print by_age.rating.mean().unstack(1).fillna(0)[10:20]

by_age.rating.mean().unstack(1).fillna(0)[5:10].plot()
show()

