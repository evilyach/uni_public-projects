select * from dbo.Masters
where
	dbo.Masters.SecondName like '%Поваринский%' or 
	dbo.Masters.SecondName like '%Жмышенко%' or
	dbo.Masters.SecondName like '%Альбертович%'