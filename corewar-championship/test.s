.name		"S.A.M."
	.comment	"Ca roxxe du chameau"

	sti		r1, %10, %1

shield:ld 10, r16
	fork	%20
	st		r1, 6
	live	%21
