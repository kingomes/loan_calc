"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.money = void 0;
var money = (function () {
    function money(interest, amountBorrowed, numPayments, years) {
        this.amountBorrowed = amountBorrowed;
        this.interest = interest;
        this.numPayments = numPayments;
        this.years = years;
    }
    money.prototype.getAmmountBorrowed = function () {
        return this.amountBorrowed;
    };
    money.prototype.setAmmountBorrowed = function (amountBorrowed) {
        this.amountBorrowed = amountBorrowed;
    };
    money.prototype.getInterest = function () {
        return this.interest;
    };
    money.prototype.setInterest = function (interest) {
        this.interest = interest;
    };
    money.prototype.getYears = function () {
        return this.years;
    };
    money.prototype.setYears = function (years) {
        this.years = years;
    };
    money.prototype.getNumPayments = function () {
        return this.numPayments;
    };
    money.prototype.setNumPayments = function (numPayments) {
        this.numPayments = numPayments;
    };
    return money;
}());
exports.money = money;
//# sourceMappingURL=money.js.map