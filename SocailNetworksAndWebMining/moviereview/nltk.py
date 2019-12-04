import nltk
from nltk.sentiment.vader import SentimentIntensityAnalyzer
sid = SentimentIntensityAnalyzer()

print "\n"
print "[REVIEW1] The Lord of the Rings: The Return of the King (2003)"
avg = 0
try:
	tot = 5
	with open('/home/xelese/moviereview/Animation_Review1.txt') as f:
	    Review = f.read().splitlines()
	f.close
	count = 0
	comp = 0.0
	stand = 0.0
	for sentence in Review:
	     ss = sid.polarity_scores(sentence)
	     comp = 5*(ss['compound'])+5
	     count+=1
	     stand += comp
	tot = stand/count
	print "Animation_Review1 = ", tot
except IOError:
	print "Animation_Review1 = ", tot
avg += tot


try:
	tot = 5
	with open('/home/xelese/moviereview/Cast_Review1.txt') as f:
	    Review = f.read().splitlines()
	f.close
	count = 0
	comp = 0.0
	stand = 0.0
	for sentence in Review:
	     ss = sid.polarity_scores(sentence)
	     comp = 5*(ss['compound'])+5
	     count+=1
	     stand += comp
	tot = stand/count
	print "Cast_Review1 = ", tot
except IOError:
	print "Cast_Review1 = ", tot
avg += tot


try:
	tot = 5
	with open('/home/xelese/moviereview/Director_Review1.txt') as f:
	    Review = f.read().splitlines()
	f.close
	count = 0
	comp = 0.0
	stand = 0.0
	for sentence in Review:
	     ss = sid.polarity_scores(sentence)
	     comp = 5*(ss['compound'])+5
	     count+=1
	     stand += comp
	tot = stand/count
	print "Director_Review1 = ", tot
except IOError:
	print "Director_Review1 = ", tot
avg += tot


try:
	tot = 5
	with open('/home/xelese/moviereview/Dressing_Review1.txt') as f:
	    Review = f.read().splitlines()
	f.close
	count = 0
	comp = 0.0
	stand = 0.0
	for sentence in Review:
	     ss = sid.polarity_scores(sentence)
	     comp = 5*(ss['compound'])+5
	     count+=1
	     stand += comp
	tot = stand/count
	print "Costume_Review1 = ", tot
except IOError:
	print "Costume_Review1 = ", tot
avg += tot


try:
	tot = 5
	with open('/home/xelese/moviereview/Music_Review1.txt') as f:
	    Review = f.read().splitlines()
	f.close
	count = 0
	comp = 0.0
	stand = 0.0
	for sentence in Review:
	     ss = sid.polarity_scores(sentence)
	     comp = 5*(ss['compound'])+5
	     count+=1
	     stand += comp
	tot = stand/count
	print "Music_Review1 = ", tot
except IOError:
	print "Music_Review1 = ", tot
avg += tot
print "MOVIE 1 SCORE = ", avg/5



print "\n"
print "[REVIEW2] Kingsman: The Golden Circle (2017)"
avg = 0
try:
	tot = 5
	with open('/home/xelese/moviereview/Animation_Review2.txt') as f:
	    Review = f.read().splitlines()
	f.close
	count = 0
	comp = 0.0
	stand = 0.0
	for sentence in Review:
	     ss = sid.polarity_scores(sentence)
	     comp = 5*(ss['compound'])+5
	     count+=1
	     stand += comp
	tot = stand/count
	print "Animation_Review2 = ", tot
except IOError:
	print "Animation_Review2 = ", tot
avg += tot


try:
	tot = 5
	with open('/home/xelese/moviereview/Cast_Review2.txt') as f:
	    Review = f.read().splitlines()
	f.close
	count = 0
	comp = 0.0
	stand = 0.0
	for sentence in Review:
	     ss = sid.polarity_scores(sentence)
	     comp = 5*(ss['compound'])+5
	     count+=1
	     stand += comp
	tot = stand/count
	print "Cast_Review2 = ", tot
except IOError:
	print "Cast_Review2 = ", tot
avg += tot


try:
	tot = 5
	with open('/home/xelese/moviereview/Director_Review2.txt') as f:
	    Review = f.read().splitlines()
	f.close
	count = 0
	comp = 0.0
	stand = 0.0
	for sentence in Review:
	     ss = sid.polarity_scores(sentence)
	     comp = 5*(ss['compound'])+5
	     count+=1
	     stand += comp
	tot = stand/count
	print "Director_Review2 = ", tot
except IOError:
	print "Director_Review2 = ", tot
avg += tot


try:
	tot = 5
	with open('/home/xelese/moviereview/Dressing_Review2.txt') as f:
	    Review = f.read().splitlines()
	f.close
	count = 0
	comp = 0.0
	stand = 0.0
	for sentence in Review:
	     ss = sid.polarity_scores(sentence)
	     comp = 5*(ss['compound'])+5
	     count+=1
	     stand += comp
	tot = stand/count
	print "Costume_Review2 = ", tot
except IOError:
	print "Costume_Review2 = ", tot
avg += tot


try:
	tot = 5
	with open('/home/xelese/moviereview/Music_Review2.txt') as f:
	    Review = f.read().splitlines()
	f.close
	count = 0
	comp = 0.0
	stand = 0.0
	for sentence in Review:
	     ss = sid.polarity_scores(sentence)
	     comp = 5*(ss['compound'])+5
	     count+=1
	     stand += comp
	tot = stand/count
	print "Music_Review2 = ", tot
except IOError:
	print "Music_Review2 = ", tot
avg += tot
print "MOVIE 2 SCORE = ", avg/5



print "\n"
print "[REVIEW3] Transformers: The Last Knight (2017)"
avg = 0
try:
	tot = 5
	with open('/home/xelese/moviereview/Animation_Review3.txt') as f:
	    Review = f.read().splitlines()
	f.close
	count = 0
	comp = 0.0
	stand = 0.0
	for sentence in Review:
	     ss = sid.polarity_scores(sentence)
	     comp = 5*(ss['compound'])+5
	     count+=1
	     stand += comp
	tot = stand/count
	print "Animation_Review3 = ", tot
except IOError:
	print "Animation_Review3 = ", tot
avg += tot


try:
	tot = 5
	with open('/home/xelese/moviereview/Cast_Review3.txt') as f:
	    Review = f.read().splitlines()
	f.close
	count = 0
	comp = 0.0
	stand = 0.0
	for sentence in Review:
	     ss = sid.polarity_scores(sentence)
	     comp = 5*(ss['compound'])+5
	     count+=1
	     stand += comp
	tot = stand/count
	print "Cast_Review3 = ", tot
except IOError:
	print "Cast_Review3 = ", tot
avg += tot


try:
	tot = 5
	with open('/home/xelese/moviereview/Director_Review3.txt') as f:
	    Review = f.read().splitlines()
	f.close
	count = 0
	comp = 0.0
	stand = 0.0
	for sentence in Review:
	     ss = sid.polarity_scores(sentence)
	     comp = 5*(ss['compound'])+5
	     count+=1
	     stand += comp
	tot = stand/count
	print "Director_Review3 = ", tot
except IOError:
	print "Director_Review3 = ", tot
avg += tot


try:
	tot = 5
	with open('/home/xelese/moviereview/Dressing_Review3.txt') as f:
	    Review = f.read().splitlines()
	f.close
	count = 0
	comp = 0.0
	stand = 0.0
	for sentence in Review:
	     ss = sid.polarity_scores(sentence)
	     comp = 5*(ss['compound'])+5
	     count+=1
	     stand += comp
	tot = stand/count
	print "Costume_Review3 = ", tot
except IOError:
	print "Costume_Review3 = ", tot
avg +=tot


try:
	tot = 5
	with open('/home/xelese/moviereview/Music_Review3.txt') as f:
	    Review = f.read().splitlines()
	f.close
	count = 0
	comp = 0.0
	stand = 0.0
	for sentence in Review:
	     ss = sid.polarity_scores(sentence)
	     comp = 5*(ss['compound'])+5
	     count+=1
	     stand += comp
	tot = stand/count
	print "Music_Review3 = ", tot
except IOError:
	print "Music_Review3 = ", tot
avg += tot
print "MOVIE 3 SCORE = ", avg/5



print "\n"
print "[REVIEW4] Baby Driver (2017)"
avg = 0
try:
	tot = 5
	with open('/home/xelese/moviereview/Animation_Review4.txt') as f:
	    Review = f.read().splitlines()
	f.close
	count = 0
	comp = 0.0
	stand = 0.0
	for sentence in Review:
	     ss = sid.polarity_scores(sentence)
	     comp = 5*(ss['compound'])+5
	     count+=1
	     stand += comp
	tot = stand/count
	print "Animation_Review4 = ", tot
except IOError:
	print "Animation_Review4 = ", tot
avg += tot


try:
	tot = 5
	with open('/home/xelese/moviereview/Cast_Review4.txt') as f:
	    Review = f.read().splitlines()
	f.close
	count = 0
	comp = 0.0
	stand = 0.0
	for sentence in Review:
	     ss = sid.polarity_scores(sentence)
	     comp = 5*(ss['compound'])+5
	     count+=1
	     stand += comp
	tot = stand/count
	print "Cast_Review4 = ", tot
except IOError:
	print "Cast_Review4 = ", tot
avg += tot


try:
	tot = 5
	with open('/home/xelese/moviereview/Director_Review4.txt') as f:
	    Review = f.read().splitlines()
	f.close
	count = 0
	comp = 0.0
	stand = 0.0
	for sentence in Review:
	     ss = sid.polarity_scores(sentence)
	     comp = 5*(ss['compound'])+5
	     count+=1
	     stand += comp
	tot = stand/count
	print "Director_Review4 = ", tot
except IOError:
	print "Director_Review4 = ", tot
avg += tot


try:
	tot = 5
	with open('/home/xelese/moviereview/Dressing_Review4.txt') as f:
	    Review = f.read().splitlines()
	f.close
	count = 0
	comp = 0.0
	stand = 0.0
	for sentence in Review:
	     ss = sid.polarity_scores(sentence)
	     comp = 5*(ss['compound'])+5
	     count+=1
	     stand += comp
	tot = stand/count
	print "Costume_Review4 = ", tot
except IOError:
	print "Costume_Review4 = ", tot
avg += tot


try:
	tot = 5
	with open('/home/xelese/moviereview/Music_Review4.txt') as f:
	    Review = f.read().splitlines()
	f.close
	count = 0
	comp = 0.0
	stand = 0.0
	for sentence in Review:
	     ss = sid.polarity_scores(sentence)
	     comp = 5*(ss['compound'])+5
	     count+=1
	     stand += comp
	tot = stand/count
	print "Music_Review4 = ", tot
except IOError:
	print "Music_Review4 = ", tot
avg += tot
print "MOVIE 4 SCORE = ", avg/5



print "\n"
print "[REVIEW5] The Hitman's Bodyguard (2017)"
avg = 0
try:
	tot = 5
	with open('/home/xelese/moviereview/Animation_Review5.txt') as f:
	    Review = f.read().splitlines()
	f.close
	count = 0
	comp = 0.0
	stand = 0.0
	for sentence in Review:
	     ss = sid.polarity_scores(sentence)
	     comp = 5*(ss['compound'])+5
	     count+=1
	     stand += comp
	tot = stand/count
	print "Animation_Review5 = ", tot
except IOError:
	print "Animation_Review5 = ", tot
avg += tot


try:
	tot = 5
	with open('/home/xelese/moviereview/Cast_Review5.txt') as f:
	    Review = f.read().splitlines()
	f.close
	count = 0
	comp = 0.0
	stand = 0.0
	for sentence in Review:
	     ss = sid.polarity_scores(sentence)
	     comp = 5*(ss['compound'])+5
	     count+=1
	     stand += comp
	tot = stand/count
	print "Cast_Review5 = ", tot
except IOError:
	print "Cast_Review5 = ", tot
avg += tot


try:
	tot = 5
	with open('/home/xelese/moviereview/Director_Review5.txt') as f:
	    Review = f.read().splitlines()
	f.close
	count = 0
	comp = 0.0
	stand = 0.0
	for sentence in Review:
	     ss = sid.polarity_scores(sentence)
	     comp = 5*(ss['compound'])+5
	     count+=1
	     stand += comp
	tot = stand/count
	print "Director_Review5 = ", tot
except IOError:
	print "Director_Review5 = ", tot
avg += tot


try:
	tot = 5
	with open('/home/xelese/moviereview/Dressing_Review5.txt') as f:
	    Review = f.read().splitlines()
	f.close
	count = 0
	comp = 0.0
	stand = 0.0
	for sentence in Review:
	     ss = sid.polarity_scores(sentence)
	     comp = 5*(ss['compound'])+5
	     count+=1
	     stand += comp
	tot = stand/count
	print "Costume_Review5 = ", tot
except IOError:
	print "Costume_Review5 = ", tot
avg += tot


try:
	tot = 5
	with open('/home/xelese/moviereview/Music_Review5.txt') as f:
	    Review = f.read().splitlines()
	f.close
	count = 0
	comp = 0.0
	stand = 0.0
	for sentence in Review:
	     ss = sid.polarity_scores(sentence)
	     comp = 5*(ss['compound'])+5
	     count+=1
	     stand += comp
	tot = stand/count
	print "Music_Review5 = ", tot
except IOError:
	print "Music_Review5 = ", tot
avg += tot
print "MOVIE 5 SCORE = ", avg/5


