-- Daily reward system (pkodev.mod.reward)
-- Transfer the list of items to the system
function GetRewardArrayAdapter(role)
	
	-- Get a list of items for daily reward
	local arr = GetRewardArray(role)
	
	-- Transfer the list to the system
	return arr[1].id, arr[1].number, arr[2].id, arr[2].number, arr[3].id, arr[3].number, arr[4].id, arr[4].number, arr[5].id, arr[5].number, arr[6].id, arr[6].number, arr[7].id, arr[7].number

end

-- Daily reward system (pkodev.mod.reward)
-- Get a list of items for daily reward
function GetRewardArray(role)

	-- Select an item depending on character race
	local hairstyle_book = function(role)
		
		-- List of items
		-- ID: 931 Lance Trendy Hairstyle Book
		-- ID: 932 Carsise Trendy Hairstyle Book
		-- ID: 933 Phyllis Trendy Hairstyle Book
		-- ID: 934 Ami Trendy Hairstyle Book
		local items = {931, 932, 933, 934}
		
		-- Get character type ID
		local id = GetChaTypeID(role)
		
		-- Return item id depending on the type ID
		return items[id] or 0
		
	end

	-- Make a list of items for daily reward
	local items = {
		
		-- Day 1 (Short Sword x 1 or Long Sword x 1 or Fencing Sword x 1)
		{id = math.random(1, 3), number = 1},
		
		-- Day 2 (Apple x 99 or Bread x 99 or Cake x 99)
		{id = math.random(1847, 1849), number = 99},
		
		-- Day 3 (Fairy Coin x 50)
		{id = 855, number = 50},
		
		-- Day 4 (Random fairy ID 183 ... 193 x 1)
		{id = math.random(183, 193), number = 1},
		
		-- Day 5 (Hairstyle Book x 1)
		{id = hairstyle_book(role), number = 1},
		
		-- Day 6 (Fairy Ration x 10)
		{id = 227, number = 10},
		
		-- Day 7 (Refining Gem x 1)
		{id = 885, number = 1}
		
	}
	
	-- We have to return an array of items to caller function
	return items

end