import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

raw_data = {'first_name': ['Lotr', 'Kingsman', 'Transformers', 'Baby_driver', 'Hitmans_bodyguard'],
        'Animation': [7, 7, 6, 8, 8],
        'Cast': [6, 5, 7, 6, 7],
        'Director': [6, 6, 6, 5, 5],
	'Costume': [7, 8, 5, 5, 5],
	'Music': [6, 3, 5, 5, 5]}
df = pd.DataFrame(raw_data, columns = ['first_name', 'Animation', 'Cast', 'Director','Costume','Music'])
df

# Setting the positions and width for the bars
pos = list(range(len(df['Animation']))) 
width = 0.05 

# Plotting the bars
fig, ax = plt.subplots(figsize=(12,5))

# Create a bar with Animation data,
# in position pos,
plt.bar(pos, 
        #using df['Animation'] data,
        df['Animation'], 
        # of width
        width, 
        # with alpha 0.5
        alpha=0.5, 
        # with color
        color='#EE3224', 
        # with label the first value in first_name
        label=df['first_name'][0]) 

# Create a bar with Cast data,
# in position pos + some width buffer,
plt.bar([p+0.04 + width*0.25 for p in pos], 
        #using df['Cast'] data,
        df['Cast'],
        # of width
        width, 
        # with alpha 0.5
        alpha=0.5, 
        # with color
        color='#F78F1E', 
        # with label the second value in first_name
        label=df['first_name'][1]) 

# Create a bar with Director data,
# in position pos + some width buffer,
plt.bar([p + 0.06 + width*0.75 for p in pos], 
        #using df['Director'] data,
        df['Director'], 
        # of width
        width, 
        # with alpha 0.5
        alpha=0.5, 
        # with color
        color='#FFC222', 
        # with label the third value in first_name
        label=df['first_name'][2])

 
# Create a bar with Costume data,
# in position pos + some width buffer,
plt.bar([p +0.08+ width*1.25 for p in pos], 
        #using df['Costume'] data,
        df['Costume'],
        # of width
        width, 
        # with alpha 0.5
        alpha=0.5, 
        # with color
        color='#FFFF00', 
        # with label the second value in first_name
        label=df['first_name'][3])

# Create a bar with Music data,
# in position pos + some width buffer,
plt.bar([p +0.12+ width*1.65 for p in pos], 
        #using df['Music'] data,
        df['Music'],
        # of width
        width, 
        # with alpha 0.5
        alpha=0.5, 
        # with color
        color='#800000', 
        # with label the second value in first_name
        label=df['first_name'][4])

# Set the y axis label
ax.set_ylabel('Score')

# Set the chart's title
ax.set_title('Movie Review Scores')

# Set the position of the x ticks
ax.set_xticks([p + 1.5 * width for p in pos])

# Set the labels for the x ticks
ax.set_xticklabels(df['first_name'])

# Setting the x-axis and y-axis limits
plt.xlim(min(pos)-width, max(pos)+width*6)
plt.ylim([0, max(df['Animation'] + df['Cast'] + df['Director'])] )

# Adding the legend and showing the plot
plt.legend(['Animation', 'Cast', 'Director','Costume','Music'], loc='upper left')
plt.grid()
plt.show()
