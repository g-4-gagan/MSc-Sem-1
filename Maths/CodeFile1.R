df <- read.csv("Dataset/RS_Session_248_AS_9.csv", header=TRUE,stringsAsFactors = FALSE, fill = TRUE, row.names =  1)

cat("\nStructure of Dataset in Consideration:\n")
str(df, vec.len = 1) 

cat("\nColumn names:- \n")
print(names(df))

cat("\nFirst Five records of the Dataset:\n")
print(head(df))

cat("\nSummary of the Dataset:\n")
print(summary(df))

# library(hash)
library(ggplot2)
library(devtools)
# library(highcharter)

h<-c(
  "==100"= nrow(df[df$Schools.with.Girls..Toilet==100, ])
)
i <- 98

while (i >= 94) {
  h[paste(">=", i)] = nrow(df[df$Schools.with.Girls..Toilet>=i, ])
  i <- i-2
}

h[">89"] = nrow(df[df$Schools.with.Girls..Toilet>89, ])

print(h)

print(barplot(h))

temp = tail(df[order(df$Schools.with.Girls..Toilet, decreasing = TRUE), ])
print(temp)

print(ggplot(temp, aes(y =  States.UTs,x=Schools.with.Girls..Toilet)) +
    geom_bar(stat='identity')+
    coord_flip()+
    xlab("Percentage") +
    ylab("States") +
    ggtitle("Last 6 states Percentage of Girls' Toilets in Schools"))

temp1 = df[df$Schools.with.Girls..Toilet>=99 & df$Schools.with.functional.Girls..Toilet==100, ]
print(temp1)

print(ggplot(temp1, aes(y =  States.UTs,x=Schools.with.Girls..Toilet)) +
  geom_bar(stat='identity')+
  coord_flip()+
  xlab("Percentage") +
  ylab("States") +
  ggtitle("States with 100% functional and more than 99% of Girls' Toilets in Schools"))

# print(nrow(df[df$Schools.with.Girls..Toilet==100, ]))

df$aggregated.functional.percentage <- (df$Schools.with.Girls..Toilet * df$Schools.with.functional.Girls..Toilet)/100

last_six = tail(df[order(df$aggregated.functional.percentage, decreasing = TRUE), ])
print(last_six[,c(1,4)])

print(ggplot(last_six, aes(y =  States.UTs,x=aggregated.functional.percentage)) +
        geom_bar(stat='identity')+
        coord_flip()+
        xlab("Aggregated Percentage") +
        ylab("States") +
        ggtitle("States with lowest aggregated percentage of Functional and total Toilets"))

print(summary(df$aggregated.functional.percentage))

print(ggplot(df, aes(x=Schools.with.Girls..Toilet)) + 
  geom_boxplot() +
  coord_flip()+
  xlab("Percentage") +
  # ylab("Percentage") +
  ggtitle("Summary of Aggregated Girls' Toilets Percentage in Schools"))
