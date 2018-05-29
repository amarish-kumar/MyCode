__author__ = 'Ashish'
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
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

lens.reset_index('movie_id', inplace=True)

pivoted = lens.pivot_table(rows=['movie_id', 'title'],
                           cols=['sex'],
                           values='rating',
                           fill_value=0)
print pivoted.head()
most_50 = lens.groupby('movie_id').size().order(ascending=False)[:50]
pivoted['diff'] = pivoted.M - pivoted.F
pivoted.reset_index('movie_id', inplace=True)
disagreements = pivoted[pivoted.movie_id.isin(most_50.index)]['diff']
disagreements.order().plot(kind='barh', figsize=[5, 5])
plt.title('Male vs. Female Avg. Ratings\n(Difference > 0 = Favored by Men)')
plt.ylabel('Title')
plt.xlabel('Average Rating Difference')
plt.show()






