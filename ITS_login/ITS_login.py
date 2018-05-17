from selenium import webdriver
from selenium.webdriver.common.keys import Keys 

driver = webdriver.Firefox()
driver.get("https://www.google.com")
input_element = driver.find_element_by_id("un")
input_element.send_keys("B417050")
input_element = driver.find_element_by_id("pd")
input_element.send_keys("Unity*#1134*")
input_element.send_keys(Keys.ENTER)