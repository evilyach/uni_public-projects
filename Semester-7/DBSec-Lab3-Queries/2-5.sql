select * from dbo.Cars
where
	dbo.Cars.Brand like 'K%' or
	dbo.Cars.Brand like 'Â%' or
	dbo.Cars.Brand like 'Ç%'