USE [CarServiceDB]
GO
/****** Object:  UserDefinedFunction [dbo].[get_quantity_by_brand]    Script Date: 14.10.2019 12:45:22 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
ALTER function [dbo].[getQuantityByBrand] (@BRAND text) returns int
with execute as caller as
begin
	declare @quantity int;
	set @quantity = (select count(*) from dbo.Cars
		where cast(@BRAND as varchar(max)) = cast(dbo.Cars.Brand as varchar(max))
		group by cast(dbo.Cars.Brand as varchar(max)));

	return @quantity;
end;

