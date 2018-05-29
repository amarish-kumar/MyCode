import youtube_dl
from bs4 import BeautifulSoup as BS, SoupStrainer as SS
import requests

course_code = 'RDQMrrM3s_cosug'#'PL385A53B00B8B158E'
url = 'https://www.youtube.com/watch?v=Kd57YHWqrsI&list='+course_code
resp = requests.get(url)
print resp.url
html = resp.content
resp.close()

ss = SS('tr')
soup = BS(html, 'html.parser', parse_only=ss)

base_url = 'https://www.youtube.com/watch?v={0}&index={1}&list='+course_code
fn1 = lambda tag:tag.has_attr('data-video-id') and tag.has_attr('class') and "yt-uix-tile" in tag.attrs['class']
cnt = 1
for tag in soup.find_all(fn1):
    #print tag.attrs#.tr.attrs
    url = base_url.format(str(tag.attrs['data-video-id']),str(cnt))
    print url
    cnt += 1
    youtube_dl.YoutubeDL().download([url])