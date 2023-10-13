# Write your MySQL query statement below

# select * from Register as r left join  Users as u on u.user_id=r.user_id  group by r.contest_id ;

select r.contest_id , round((count(r.contest_id)/(select count(*) from Users))*100 ,2) as percentage from Register as r left join  Users as u on u.user_id=r.user_id group by r.contest_id order by percentage DESC, r.contest_id ASC;

# select contest_id , count(*) from Register group by contest_id;

