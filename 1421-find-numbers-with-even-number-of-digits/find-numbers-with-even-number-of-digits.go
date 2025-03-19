func findNumbers(nums []int) int {
	c := 0
	for _, num := range nums {
		s := strconv.Itoa(num)
		if len(s)%2 == 0 {
			c += 1
		}
	}
	return c
}