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

print(tail(df[order(df$Schools.with.Girls..Toilet, decreasing = TRUE), ]))

df[df$Schools.with.Girls..Toilet>=99 & df$Schools.with.functional.Girls..Toilet==100, ]

# print(nrow(df[df$Schools.with.Girls..Toilet==100, ]))

