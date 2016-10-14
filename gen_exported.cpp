#include "gen_exported.h"

namespace gen_exported {


/*******************************************************************************************************************
 Cycling '74 License for Max-Generated Code for Export
 Copyright (c) 2016 Cycling '74
 The code that Max generates automatically and that end users are capable of exporting and using, and any
 associated documentation files (the “Software”) is a work of authorship for which Cycling '74 is the author
 and owner for copyright purposes.  A license is hereby granted, free of charge, to any person obtaining a
 copy of the Software (“Licensee”) to use, copy, modify, merge, publish, and distribute copies of the Software,
 and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
 The Software is licensed to Licensee only for non-commercial use. Users who wish to make commercial use of the
 Software must contact the copyright owner to determine if a license for commercial use is available, and the
 terms and conditions for same, which may include fees or royalties. For commercial use, please send inquiries
 to licensing@cycling74.com.  The determination of whether a use is commercial use or non-commercial use is based
 upon the use, not the user. The Software may be used by individuals, institutions, governments, corporations, or
 other business whether for-profit or non-profit so long as the use itself is not a commercialization of the
 materials or a use that generates or is intended to generate income, revenue, sales or profit.
 The above copyright notice and this license shall be included in all copies or substantial portions of the Software.
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO
 THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. IN NO EVENT SHALL
 THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
 CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 DEALINGS IN THE SOFTWARE.
 *******************************************************************************************************************/

// global noise generator
Noise noise;
static const int GENLIB_LOOPCOUNT_BAIL = 100000;


// The State struct contains all the state and procedures for the gendsp kernel
typedef struct State {
	CommonState __commonstate;
	Delay m_delay_44;
	Delay m_delay_24;
	Delay m_delay_25;
	Delay m_delay_27;
	Delay m_delay_23;
	Delay m_delay_43;
	Delay m_delay_22;
	Delay m_delay_19;
	Delay m_delay_17;
	Delay m_delay_29;
	Delay m_delay_33;
	Delay m_delay_41;
	Delay m_delay_42;
	Delay m_delay_31;
	Delay m_delay_39;
	Delay m_delay_35;
	Delay m_delay_37;
	Delay m_delay_15;
	Delay m_delay_21;
	Delay m_delay_9;
	Delay m_delay_5;
	Delay m_delay_13;
	Delay m_delay_7;
	Delay m_delay_11;
	int __exception;
	int vectorsize;
	t_sample m_history_36;
	t_sample m_spread_3;
	t_sample m_history_34;
	t_sample m_history_40;
	t_sample m_damp_1;
	t_sample m_history_38;
	t_sample m_fb_2;
	t_sample samplerate;
	t_sample m_fb_4;
	t_sample m_history_30;
	t_sample m_history_16;
	t_sample m_history_12;
	t_sample m_history_20;
	t_sample m_history_18;
	t_sample m_history_32;
	t_sample m_history_10;
	t_sample m_history_26;
	t_sample m_history_8;
	t_sample m_history_6;
	t_sample m_history_28;
	t_sample m_history_14;
	// re-initialize all member variables;
	inline void reset(t_param __sr, int __vs) {
		__exception = 0;
		vectorsize = __vs;
		samplerate = __sr;
		m_damp_1 = 0.5;
		m_fb_2 = 0.9;
		m_spread_3 = 0;
		m_fb_4 = 0.5;
		m_delay_5.reset("m_delay_5", 2000);
		m_history_6 = 0;
		m_delay_7.reset("m_delay_7", 2000);
		m_history_8 = 0;
		m_delay_9.reset("m_delay_9", 2000);
		m_history_10 = 0;
		m_delay_11.reset("m_delay_11", 2000);
		m_history_12 = 0;
		m_delay_13.reset("m_delay_13", 2000);
		m_history_14 = 0;
		m_delay_15.reset("m_delay_15", 2000);
		m_history_16 = 0;
		m_delay_17.reset("m_delay_17", 2000);
		m_history_18 = 0;
		m_delay_19.reset("m_delay_19", 2000);
		m_history_20 = 0;
		m_delay_21.reset("m_delay_21", 2000);
		m_delay_22.reset("m_delay_22", 2000);
		m_delay_23.reset("m_delay_23", 2000);
		m_delay_24.reset("m_delay_24", 2000);
		m_delay_25.reset("m_delay_25", 2000);
		m_history_26 = 0;
		m_delay_27.reset("m_delay_27", 2000);
		m_history_28 = 0;
		m_delay_29.reset("m_delay_29", 2000);
		m_history_30 = 0;
		m_delay_31.reset("m_delay_31", 2000);
		m_history_32 = 0;
		m_delay_33.reset("m_delay_33", 2000);
		m_history_34 = 0;
		m_delay_35.reset("m_delay_35", 2000);
		m_history_36 = 0;
		m_delay_37.reset("m_delay_37", 2000);
		m_history_38 = 0;
		m_delay_39.reset("m_delay_39", 2000);
		m_history_40 = 0;
		m_delay_41.reset("m_delay_41", 2000);
		m_delay_42.reset("m_delay_42", 2000);
		m_delay_43.reset("m_delay_43", 2000);
		m_delay_44.reset("m_delay_44", 2000);
		genlib_reset_complete(this);

	};
	// the signal processing routine;
	inline int perform(t_sample ** __ins, t_sample ** __outs, int __n) {
		vectorsize = __n;
		const t_sample * __in1 = __ins[0];
		const t_sample * __in2 = __ins[1];
		t_sample * __out1 = __outs[0];
		t_sample * __out2 = __outs[1];
		if (__exception) {
			return __exception;

		} else if (( (__in1 == 0) || (__in2 == 0) || (__out1 == 0) || (__out2 == 0) )) {
			__exception = GENLIB_ERR_NULL_BUFFER;
			return __exception;

		};
		t_sample mul_153 = (m_fb_4 * 0.5);
		t_sample mul_82 = (m_fb_4 * 0.5);
		t_sample add_137 = (225 + m_spread_3);
		t_sample add_66 = (225 + m_spread_3);
		t_sample add_140 = (341 + m_spread_3);
		t_sample add_69 = (341 + m_spread_3);
		t_sample add_151 = (441 + m_spread_3);
		t_sample add_80 = (441 + m_spread_3);
		t_sample add_134 = (556 + m_spread_3);
		t_sample add_63 = (556 + m_spread_3);
		t_sample damp_22 = m_damp_1;
		t_sample damp_111 = damp_22;
		t_sample damp_110 = damp_22;
		t_sample damp_112 = damp_22;
		t_sample damp_113 = damp_22;
		t_sample damp_114 = damp_22;
		t_sample damp_115 = damp_22;
		t_sample damp_116 = damp_22;
		t_sample damp_117 = damp_22;
		t_sample damp_21 = damp_22;
		t_sample damp_28 = damp_22;
		t_sample damp_27 = damp_22;
		t_sample damp_26 = damp_22;
		t_sample damp_25 = damp_22;
		t_sample damp_24 = damp_22;
		t_sample damp_23 = damp_22;
		t_sample add_144 = (1557 + m_spread_3);
		t_sample rsub_29 = (1 - damp_111);
		t_sample add_143 = (1617 + m_spread_3);
		t_sample rsub_383 = (1 - damp_110);
		t_sample add_145 = (1491 + m_spread_3);
		t_sample rsub_398 = (1 - damp_112);
		t_sample add_146 = (1422 + m_spread_3);
		t_sample rsub_410 = (1 - damp_113);
		t_sample add_147 = (1356 + m_spread_3);
		t_sample rsub_421 = (1 - damp_114);
		t_sample add_148 = (1277 + m_spread_3);
		t_sample rsub_431 = (1 - damp_115);
		t_sample add_149 = (1188 + m_spread_3);
		t_sample rsub_445 = (1 - damp_116);
		t_sample add_150 = (1116 + m_spread_3);
		t_sample rsub_456 = (1 - damp_117);
		t_sample add_72 = (1617 + m_spread_3);
		t_sample rsub_487 = (1 - damp_21);
		t_sample add_79 = (1116 + m_spread_3);
		t_sample rsub_499 = (1 - damp_28);
		t_sample add_78 = (1188 + m_spread_3);
		t_sample rsub_511 = (1 - damp_27);
		t_sample add_77 = (1277 + m_spread_3);
		t_sample rsub_524 = (1 - damp_26);
		t_sample add_76 = (1356 + m_spread_3);
		t_sample rsub_536 = (1 - damp_25);
		t_sample add_75 = (1422 + m_spread_3);
		t_sample rsub_547 = (1 - damp_24);
		t_sample add_74 = (1491 + m_spread_3);
		t_sample rsub_556 = (1 - damp_23);
		t_sample add_73 = (1557 + m_spread_3);
		t_sample rsub_568 = (1 - damp_22);
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			const t_sample in2 = (*(__in2++));
			t_sample mul_156 = (in1 * 0.015);
			t_sample tap_36 = m_delay_5.read_linear(add_144);
			t_sample gen_130 = tap_36;
			t_sample mul_34 = (tap_36 * damp_111);
			t_sample mul_32 = (m_history_6 * rsub_29);
			t_sample add_33 = (mul_34 + mul_32);
			t_sample mul_30 = (add_33 * m_fb_2);
			t_sample add_37 = (mul_156 + mul_30);
			t_sample history_31_next_41 = fixdenorm(add_33);
			t_sample tap_381 = m_delay_7.read_linear(add_143);
			t_sample gen_154 = tap_381;
			t_sample mul_384 = (tap_381 * damp_110);
			t_sample mul_385 = (m_history_8 * rsub_383);
			t_sample add_387 = (mul_384 + mul_385);
			t_sample mul_386 = (add_387 * m_fb_2);
			t_sample add_379 = (mul_156 + mul_386);
			t_sample history_31_next_380 = fixdenorm(add_387);
			t_sample tap_393 = m_delay_9.read_linear(add_145);
			t_sample gen_128 = tap_393;
			t_sample mul_395 = (tap_393 * damp_112);
			t_sample mul_396 = (m_history_10 * rsub_398);
			t_sample add_399 = (mul_395 + mul_396);
			t_sample mul_397 = (add_399 * m_fb_2);
			t_sample add_391 = (mul_156 + mul_397);
			t_sample history_31_next_392 = fixdenorm(add_399);
			t_sample tap_409 = m_delay_11.read_linear(add_146);
			t_sample gen_126 = tap_409;
			t_sample mul_407 = (tap_409 * damp_113);
			t_sample mul_408 = (m_history_12 * rsub_410);
			t_sample add_411 = (mul_407 + mul_408);
			t_sample mul_406 = (add_411 * m_fb_2);
			t_sample add_403 = (mul_156 + mul_406);
			t_sample history_31_next_404 = fixdenorm(add_411);
			t_sample tap_422 = m_delay_13.read_linear(add_147);
			t_sample gen_124 = tap_422;
			t_sample mul_418 = (tap_422 * damp_114);
			t_sample mul_419 = (m_history_14 * rsub_421);
			t_sample add_423 = (mul_418 + mul_419);
			t_sample mul_420 = (add_423 * m_fb_2);
			t_sample add_415 = (mul_156 + mul_420);
			t_sample history_31_next_416 = fixdenorm(add_423);
			t_sample tap_435 = m_delay_15.read_linear(add_148);
			t_sample gen_122 = tap_435;
			t_sample mul_432 = (tap_435 * damp_115);
			t_sample mul_433 = (m_history_16 * rsub_431);
			t_sample add_436 = (mul_432 + mul_433);
			t_sample mul_434 = (add_436 * m_fb_2);
			t_sample add_427 = (mul_156 + mul_434);
			t_sample history_31_next_428 = fixdenorm(add_436);
			t_sample tap_440 = m_delay_17.read_linear(add_149);
			t_sample gen_120 = tap_440;
			t_sample mul_446 = (tap_440 * damp_116);
			t_sample mul_443 = (m_history_18 * rsub_445);
			t_sample add_447 = (mul_446 + mul_443);
			t_sample mul_441 = (add_447 * m_fb_2);
			t_sample add_444 = (mul_156 + mul_441);
			t_sample history_31_next_439 = fixdenorm(add_447);
			t_sample tap_458 = m_delay_19.read_linear(add_150);
			t_sample gen_118 = tap_458;
			t_sample mul_457 = (tap_458 * damp_117);
			t_sample mul_454 = (m_history_20 * rsub_456);
			t_sample add_459 = (mul_457 + mul_454);
			t_sample mul_452 = (add_459 * m_fb_2);
			t_sample add_455 = (mul_156 + mul_452);
			t_sample history_31_next_451 = fixdenorm(add_459);
			t_sample add_152 = ((((((((gen_118 + gen_120) + gen_122) + gen_124) + gen_126) + gen_128) + gen_154) + gen_130) + 0);
			t_sample tap_59 = m_delay_21.read_linear(add_134);
			t_sample sub_55 = (add_152 - tap_59);
			t_sample mul_57 = (tap_59 * mul_153);
			t_sample add_56 = (add_152 + mul_57);
			t_sample tap_467 = m_delay_22.read_linear(add_151);
			t_sample sub_464 = (sub_55 - tap_467);
			t_sample mul_465 = (tap_467 * mul_153);
			t_sample add_466 = (sub_55 + mul_465);
			t_sample tap_473 = m_delay_23.read_linear(add_140);
			t_sample sub_470 = (sub_464 - tap_473);
			t_sample mul_471 = (tap_473 * mul_153);
			t_sample add_472 = (sub_464 + mul_471);
			t_sample tap_479 = m_delay_24.read_linear(add_137);
			t_sample sub_476 = (sub_470 - tap_479);
			t_sample mul_477 = (tap_479 * mul_153);
			t_sample add_478 = (sub_470 + mul_477);
			t_sample out1 = sub_476;
			t_sample mul_85 = (in2 * 0.015);
			t_sample tap_482 = m_delay_25.read_linear(add_72);
			t_sample gen_83 = tap_482;
			t_sample mul_488 = (tap_482 * damp_21);
			t_sample mul_485 = (m_history_26 * rsub_487);
			t_sample add_489 = (mul_488 + mul_485);
			t_sample mul_483 = (add_489 * m_fb_2);
			t_sample add_486 = (mul_85 + mul_483);
			t_sample history_31_next_481 = fixdenorm(add_489);
			t_sample tap_502 = m_delay_27.read_linear(add_79);
			t_sample gen_155 = tap_502;
			t_sample mul_500 = (tap_502 * damp_28);
			t_sample mul_496 = (m_history_28 * rsub_499);
			t_sample add_501 = (mul_500 + mul_496);
			t_sample mul_494 = (add_501 * m_fb_2);
			t_sample add_497 = (mul_85 + mul_494);
			t_sample history_31_next_493 = fixdenorm(add_501);
			t_sample tap_514 = m_delay_29.read_linear(add_78);
			t_sample gen_43 = tap_514;
			t_sample mul_512 = (tap_514 * damp_27);
			t_sample mul_508 = (m_history_30 * rsub_511);
			t_sample add_513 = (mul_512 + mul_508);
			t_sample mul_506 = (add_513 * m_fb_2);
			t_sample add_509 = (mul_85 + mul_506);
			t_sample history_31_next_505 = fixdenorm(add_513);
			t_sample tap_522 = m_delay_31.read_linear(add_77);
			t_sample gen_45 = tap_522;
			t_sample mul_525 = (tap_522 * damp_26);
			t_sample mul_520 = (m_history_32 * rsub_524);
			t_sample add_526 = (mul_525 + mul_520);
			t_sample mul_518 = (add_526 * m_fb_2);
			t_sample add_521 = (mul_85 + mul_518);
			t_sample history_31_next_517 = fixdenorm(add_526);
			t_sample tap_530 = m_delay_33.read_linear(add_76);
			t_sample gen_47 = tap_530;
			t_sample mul_537 = (tap_530 * damp_25);
			t_sample mul_533 = (m_history_34 * rsub_536);
			t_sample add_538 = (mul_537 + mul_533);
			t_sample mul_531 = (add_538 * m_fb_2);
			t_sample add_534 = (mul_85 + mul_531);
			t_sample history_31_next_529 = fixdenorm(add_538);
			t_sample tap_542 = m_delay_35.read_linear(add_75);
			t_sample gen_49 = tap_542;
			t_sample mul_548 = (tap_542 * damp_24);
			t_sample mul_544 = (m_history_36 * rsub_547);
			t_sample add_550 = (mul_548 + mul_544);
			t_sample mul_546 = (add_550 * m_fb_2);
			t_sample add_545 = (mul_85 + mul_546);
			t_sample history_31_next_541 = fixdenorm(add_550);
			t_sample tap_558 = m_delay_37.read_linear(add_74);
			t_sample gen_51 = tap_558;
			t_sample mul_561 = (tap_558 * damp_23);
			t_sample mul_555 = (m_history_38 * rsub_556);
			t_sample add_557 = (mul_561 + mul_555);
			t_sample mul_560 = (add_557 * m_fb_2);
			t_sample add_562 = (mul_85 + mul_560);
			t_sample history_31_next_553 = fixdenorm(add_557);
			t_sample tap_572 = m_delay_39.read_linear(add_73);
			t_sample gen_53 = tap_572;
			t_sample mul_573 = (tap_572 * damp_22);
			t_sample mul_567 = (m_history_40 * rsub_568);
			t_sample add_569 = (mul_573 + mul_567);
			t_sample mul_571 = (add_569 * m_fb_2);
			t_sample add_574 = (mul_85 + mul_571);
			t_sample history_31_next_565 = fixdenorm(add_569);
			t_sample add_81 = ((((((((gen_53 + gen_51) + gen_49) + gen_47) + gen_45) + gen_43) + gen_155) + gen_83) + 0);
			t_sample tap_580 = m_delay_41.read_linear(add_63);
			t_sample sub_577 = (add_81 - tap_580);
			t_sample mul_581 = (tap_580 * mul_82);
			t_sample add_579 = (add_81 + mul_581);
			t_sample tap_586 = m_delay_42.read_linear(add_80);
			t_sample sub_583 = (sub_577 - tap_586);
			t_sample mul_587 = (tap_586 * mul_82);
			t_sample add_585 = (sub_577 + mul_587);
			t_sample tap_592 = m_delay_43.read_linear(add_69);
			t_sample sub_589 = (sub_583 - tap_592);
			t_sample mul_593 = (tap_592 * mul_82);
			t_sample add_591 = (sub_583 + mul_593);
			t_sample tap_598 = m_delay_44.read_linear(add_66);
			t_sample sub_595 = (sub_589 - tap_598);
			t_sample mul_599 = (tap_598 * mul_82);
			t_sample add_597 = (sub_589 + mul_599);
			t_sample out2 = sub_595;
			m_delay_5.write(add_37);
			m_delay_44.write(add_597);
			m_delay_43.write(add_591);
			m_delay_42.write(add_585);
			m_delay_41.write(add_579);
			m_history_40 = history_31_next_565;
			m_delay_39.write(add_574);
			m_history_38 = history_31_next_553;
			m_delay_37.write(add_562);
			m_history_36 = history_31_next_541;
			m_delay_35.write(add_545);
			m_history_34 = history_31_next_529;
			m_delay_33.write(add_534);
			m_history_32 = history_31_next_517;
			m_delay_31.write(add_521);
			m_history_30 = history_31_next_505;
			m_delay_29.write(add_509);
			m_history_28 = history_31_next_493;
			m_delay_27.write(add_497);
			m_history_26 = history_31_next_481;
			m_delay_25.write(add_486);
			m_delay_24.write(add_478);
			m_delay_23.write(add_472);
			m_delay_22.write(add_466);
			m_delay_21.write(add_56);
			m_history_20 = history_31_next_451;
			m_delay_19.write(add_455);
			m_history_18 = history_31_next_439;
			m_delay_17.write(add_444);
			m_history_16 = history_31_next_428;
			m_delay_15.write(add_427);
			m_history_14 = history_31_next_416;
			m_delay_13.write(add_415);
			m_history_12 = history_31_next_404;
			m_delay_11.write(add_403);
			m_history_10 = history_31_next_392;
			m_delay_9.write(add_391);
			m_history_8 = history_31_next_380;
			m_delay_7.write(add_379);
			m_history_6 = history_31_next_41;
			m_delay_5.step();
			m_delay_7.step();
			m_delay_9.step();
			m_delay_11.step();
			m_delay_13.step();
			m_delay_15.step();
			m_delay_17.step();
			m_delay_19.step();
			m_delay_21.step();
			m_delay_22.step();
			m_delay_23.step();
			m_delay_24.step();
			m_delay_25.step();
			m_delay_27.step();
			m_delay_29.step();
			m_delay_31.step();
			m_delay_33.step();
			m_delay_35.step();
			m_delay_37.step();
			m_delay_39.step();
			m_delay_41.step();
			m_delay_42.step();
			m_delay_43.step();
			m_delay_44.step();
			// assign results to output buffer;
			(*(__out1++)) = out1;
			(*(__out2++)) = out2;

		};
		return __exception;

	};
	inline void set_damp(t_param _value) {
		m_damp_1 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_fb1(t_param _value) {
		m_fb_2 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_spread(t_param _value) {
		m_spread_3 = (_value < 0 ? 0 : (_value > 400 ? 400 : _value));
	};
	inline void set_fb2(t_param _value) {
		m_fb_4 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};

} State;


///
///	Configuration for the genlib API
///

/// Number of signal inputs and outputs

int gen_kernel_numins = 2;
int gen_kernel_numouts = 2;

int num_inputs() { return gen_kernel_numins; }
int num_outputs() { return gen_kernel_numouts; }
int num_params() { return 4; }

/// Assistive lables for the signal inputs and outputs

const char * gen_kernel_innames[] = { "in1", "in2" };
const char * gen_kernel_outnames[] = { "out1", "out2" };

/// Invoke the signal process of a State object

int perform(CommonState *cself, t_sample **ins, long numins, t_sample **outs, long numouts, long n) {
	State * self = (State *)cself;
	return self->perform(ins, outs, n);
}

/// Reset all parameters and stateful operators of a State object

void reset(CommonState *cself) {
	State * self = (State *)cself;
	self->reset(cself->sr, cself->vs);
}

/// Set a parameter of a State object

void setparameter(CommonState *cself, long index, t_param value, void *ref) {
	State * self = (State *)cself;
	switch (index) {
		case 0: self->set_damp(value); break;
		case 1: self->set_fb1(value); break;
		case 2: self->set_fb2(value); break;
		case 3: self->set_spread(value); break;

		default: break;
	}
}

/// Get the value of a parameter of a State object

void getparameter(CommonState *cself, long index, t_param *value) {
	State *self = (State *)cself;
	switch (index) {
		case 0: *value = self->m_damp_1; break;
		case 1: *value = self->m_fb_2; break;
		case 2: *value = self->m_fb_4; break;
		case 3: *value = self->m_spread_3; break;

		default: break;
	}
}

/// Get the name of a parameter of a State object

const char *getparametername(CommonState *cself, long index) {
	if (index >= 0 && index < cself->numparams) {
		return cself->params[index].name;
	}
	return 0;
}

/// Get the minimum value of a parameter of a State object

t_param getparametermin(CommonState *cself, long index) {
	if (index >= 0 && index < cself->numparams) {
		return cself->params[index].outputmin;
	}
	return 0;
}

/// Get the maximum value of a parameter of a State object

t_param getparametermax(CommonState *cself, long index) {
	if (index >= 0 && index < cself->numparams) {
		return cself->params[index].outputmax;
	}
	return 0;
}

/// Get parameter of a State object has a minimum and maximum value

char getparameterhasminmax(CommonState *cself, long index) {
	if (index >= 0 && index < cself->numparams) {
		return cself->params[index].hasminmax;
	}
	return 0;
}

/// Get the units of a parameter of a State object

const char *getparameterunits(CommonState *cself, long index) {
	if (index >= 0 && index < cself->numparams) {
		return cself->params[index].units;
	}
	return 0;
}

/// Get the size of the state of all parameters of a State object

size_t getstatesize(CommonState *cself) {
	return genlib_getstatesize(cself, &getparameter);
}

/// Get the state of all parameters of a State object

short getstate(CommonState *cself, char *state) {
	return genlib_getstate(cself, state, &getparameter);
}

/// set the state of all parameters of a State object

short setstate(CommonState *cself, const char *state) {
	return genlib_setstate(cself, state, &setparameter);
}

/// Allocate and configure a new State object and it's internal CommonState:

void * create(t_param sr, long vs) {
	State *self = new State;
	self->reset(sr, vs);
	ParamInfo *pi;
	self->__commonstate.inputnames = gen_kernel_innames;
	self->__commonstate.outputnames = gen_kernel_outnames;
	self->__commonstate.numins = gen_kernel_numins;
	self->__commonstate.numouts = gen_kernel_numouts;
	self->__commonstate.sr = sr;
	self->__commonstate.vs = vs;
	self->__commonstate.params = (ParamInfo *)genlib_sysmem_newptr(4 * sizeof(ParamInfo));
	self->__commonstate.numparams = 4;
	// initialize parameter 0 ("m_damp_1")
	pi = self->__commonstate.params + 0;
	pi->name = "damp";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_damp_1;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_fb_2")
	pi = self->__commonstate.params + 1;
	pi->name = "fb1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_fb_2;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_fb_4")
	pi = self->__commonstate.params + 2;
	pi->name = "fb2";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_fb_4;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 3 ("m_spread_3")
	pi = self->__commonstate.params + 3;
	pi->name = "spread";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_spread_3;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 400;
	pi->exp = 0;
	pi->units = "";		// no units defined

	return self;
}

/// Release all resources and memory used by a State object:

void destroy(CommonState *cself) {
	State * self = (State *)cself;
	genlib_sysmem_freeptr(cself->params);

	delete self;
}


} // gen_exported::
