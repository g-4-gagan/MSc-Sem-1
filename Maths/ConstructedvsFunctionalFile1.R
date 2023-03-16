df <- read.csv("Dataset/RS_Session_248_AS_9.csv", header=TRUE,stringsAsFactors = FALSE, fill = TRUE)
str(df, vec.len = 1) 
head(df)


library(ggplot2)

d1 <- data.frame(GirlsToilet <- df$Schools.with.Girls.Toilet, Locations <- df$States.UTs)

#barplot(data$Schools.with.Girls..Toilet,names.arg = data$X.1  )

d1

d2 <- data.frame(FunctionalGirlsToilet <- df$Schools.with.functional.Girls..Toilet, Locations <- df$States.UTs)
d1 <- d1[order(d1$GirlsToilet, decreasing = TRUE)]

ggplot(d1, aes(y=Locations,x=GirlsToilet)) +
  geom_bar(stat='identity')+
  coord_flip()+
 coord_cartesian(xlim =c(85.0, 100.0))+
  ggtitle("Percentage of Girls' Toilets in Schools")

ggplot(d2, aes(y=Locations,x=FunctionalGirlsToilet)) +
  geom_bar(stat='identity')+
  coord_flip()+
  coord_cartesian(xlim =c(85.0, 100.0))+
  ggtitle("Percentage of Fuctional Girls' Toilets in Schools")


x<- ggplot(df, aes(fill=df$Schools.with.functional.Girls..Toilet,
               x=df$Schools.with.Girls..Toilet,
               y=df$States.UTs)) + 
  geom_bar(position="dodge", stat="identity")
x + coord_cartesian(xlim =c(85.0, 100.0))

boxplot(df$Schools.with.Girls..Toilet, data = df)+
  title("Girls Toilets")
boxplot(df$Schools.with.functional.Girls..Toilet, data = df)+
  title("Functional Girls Toilets")




